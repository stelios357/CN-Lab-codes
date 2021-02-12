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

#ifndef __FIRST_FNODE_H_
#define __FIRST_FNODE_H_

#include <omnetpp.h>
#include <MyMsg_m.h>
#include<string.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Fnode : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    cGate * ina ;
    cGate * outa ;
    int addressa ;
    int id_num ;
    int counter1 ;
    int counter2 ;
};

#endif
