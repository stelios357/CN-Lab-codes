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

network ForwardingNetwork
{
    parameters:
        int srcAddr;
        int destAddr;
        
    submodules:
        N[5] : Node{
            addr = index;
            src_addr = srcAddr;
            dest_addr = destAddr;
        }
        
    connections allowunconnected: 
        N[0].gOut[0] --> {delay = 100ms;} --> N[1].gIn[0];
        N[1].gOut[0] --> {delay = 100ms;} --> N[0].gIn[0];
        
        N[1].gOut[1] --> {delay = 100ms;} --> N[2].gIn[0];
        N[2].gOut[0] --> {delay = 100ms;} --> N[1].gIn[1];
        
        N[1].gOut[2] --> {delay = 200ms;} --> N[3].gIn[0];
        N[3].gOut[0] --> {delay = 200ms;} --> N[1].gIn[2];
        
        N[2].gOut[1] --> {delay = 200ms;} --> N[4].gIn[0];
        N[4].gOut[0] --> {delay = 200ms;} --> N[2].gIn[1];
        
        N[3].gOut[1] --> {delay = 200ms;} --> N[4].gIn[1];
        N[4].gOut[1] --> {delay = 200ms;} --> N[3].gIn[1];        
}
