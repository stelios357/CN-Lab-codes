//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Node.h"

Define_Module(Node);

void Node::initialize()
{
    src_address = par("src_addr");
    dest_address = par("dest_addr");
    address = par("addr");

    if(address == 0)
    {
        RT = {{1, 0}, {2, 0}, {3, 0}, {4, 0}};
    }

    if(address == 1)
    {
        RT = {{0, 0}, {2, 1}, {3, 2}, {4, 1}};
    }

    if(address == 2)
    {
        RT = {{0, 0}, {1, 0}, {3, 0}, {4, 1}};
    }

    if(address == 3)
    {
        RT = {{0, 0}, {1, 0}, {2, 0}, {4, 1}};
    }

    if(address == 4)
    {
        RT = {{0, 0}, {1, 0}, {2, 0}, {3, 1}};
    }

    if(address == src_address)
    {
        cMessage *event = new cMessage();
        scheduleAt(0, event);
    }
}

void Node::handleMessage(cMessage *msg)
{
    if(msg -> isSelfMessage())
    {
        N_PDU *data = new N_PDU();
        data -> setType("DATA");
        data -> setStartTime(simTime());
        send(data, "gOut", RT.at(dest_address));
    }
    else
    {
        N_PDU *pkt = check_and_cast<N_PDU *>(msg);

        if(address == dest_address)
        {
            EV << "Delay :- "<< (pkt -> getArrivalTime() - pkt -> getStartTime())*1000 << "ms \n";
            return;
        }
        else
        {
            send(pkt, "gOut", RT.at(dest_address));
        }
    }
}
