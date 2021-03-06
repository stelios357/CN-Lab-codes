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

#ifndef __WEEK3_DLL1_H_
#define __WEEK3_DLL1_H_

#include <dll_msg_m.h>
#include <nl_msg_m.h>
#include <omnetpp.h>
#include <ack_m.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Dll1 : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    cGate * in_n ;
    cGate * out_n ;
    cGate * in_c ;
    cGate * out_c ;
    Dll_msg * copy_message;
    cMessage* timeoutEvent;
    int id ;

};

#endif
