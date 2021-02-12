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

#include "fnode.h"

Define_Module(Fnode);

void Fnode::initialize()
{
    // TODO - Generated method body

    addressa = par("address");
    ina = gate("in");
    outa = gate("out");
    id_num = 0;
    counter1 = 0;

    if(addressa==1)
    {
        cMessage *event = new cMessage();
        scheduleAt(0,event);
    }

}

void Fnode::handleMessage(cMessage *msg)
{
    // TODO - Generated method body

    if( msg->isSelfMessage()){
        MyMsg * m = new MyMsg();
        m->setPacketId(id_num++);
        m->setSourceId(1);
        m->setDestId(2);
        m->setPacketType("Data");
        send(m , outa);
    }
    else{

        if(addressa == 1){
            MyMsg * m = new MyMsg();
            m->setPacketId(id_num);
            m->setSourceId(2);
            m->setDestId(1);
            m->setPacketType("Acne");
            send(m , outa);
        }
        else{
            counter1++;
            if(counter1 >= 10){
                return;
            }
            MyMsg * m = new MyMsg();
            m->setPacketId(id_num++);
            m->setSourceId(1);
            m->setDestId(2);
            m->setPacketType("Data");
            send(m , outa);
        }
    }
}
