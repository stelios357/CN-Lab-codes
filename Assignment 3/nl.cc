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

#include "nl.h"

Define_Module(Nl);

void Nl::initialize()
{
    // TODO - Generated method body


        in = gate("nl_in");
        out = gate("nl_out");
        id =  par("nl_id");
        source = par("source");
        counter = 0;
        if(id == 1)
        {
            cMessage *event = new cMessage();
            scheduleAt(0,event);

        }
}

void Nl::handleMessage(cMessage *msg)
{

    // TODO - Generated method body
    if( msg->isSelfMessage()){
            if( remaining_packets == 10){
               return;
           }
            nl_msg * data = new nl_msg();
            data->setNl_packetType(1);
            send(data , out);
            cMessage* event = new cMessage();
            scheduleAt( simTime() + 200 , event);

    }

    else{
        delete(msg) ;
    }
}
