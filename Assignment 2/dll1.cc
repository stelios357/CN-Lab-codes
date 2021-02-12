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

#include "dll1.h"

Define_Module(Dll1);

void Dll1::initialize()
{
    id = par("dll_id");
    in_n = gate("dlln_in");
    out_n = gate("dlln_out");
    in_c = gate("dllc_in");
    out_c = gate("dllc_out");

}

void Dll1::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

    if (msg->getArrivalGate()==in_n){
        dll_msg *data = new dll_msg();
        nl_msg* data_2e = check_and_cast<nl_msg*>(msg);
        data->encapsulate(data_2e);
        data->setDll_packetType(1);
        send(data , out_c);


    }

    else if (msg->getArrivalGate()==in_c){
        dll_msg* message = check_and_cast<dll_msg*>(msg);
        if (message->getDll_packetType() ==1){
            cMessage nl_message = message->decapsulate();
            dll_msg* ack = new dll_msg();
            ack->setDll_packetType(0);
            send(nl_message, out_n);
            send(ack, out_c);

        }
        else{
            delete(msg);
        }
    }
}
