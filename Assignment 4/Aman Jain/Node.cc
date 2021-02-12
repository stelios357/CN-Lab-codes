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
    // TODO - Generated method body
    dest_address = par("dest_address");
    source_address = par("source_address");
    address = par("address");

    if (address==0){
        m = {{1,0},{2,0},{3,0},{4,0}};
    }

    else if (address==1){
        m = {{0,0},{2,1},{3,2},{4,1}};
    }

    else if (address==2){
        m = {{0,0},{1,0},{3,1},{4,1}};
    }

    else if (address==3){
        m = {{0,0},{1,0},{2,1},{4,1}};
    }

    else if (address==4){
        m = {{0,0},{1,0},{2,0},{3,1}};
    }

    if(address == source_address){
        cMessage* event = new cMessage();
        scheduleAt(0, event);
    }
}

void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    // TODO - Generated method body
    if (msg->isSelfMessage()){
        Nl_Msg* data = new Nl_Msg();
        send(data, "gOut", m.at(dest_address));
    }
    else{
        if(address == dest_address){
            Nl_Msg* data = check_and_cast<Nl_Msg*>(msg);
            delete(data);
    }

    else{
        Nl_Msg* data = check_and_cast<Nl_Msg*>(msg);
        send(data, "gOut", m.at(dest_address));
        }
    }
}
