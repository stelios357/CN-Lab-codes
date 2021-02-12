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

module Cm1
{
    parameters:
        int address;
        
   	gates:
    	input c_in;
    	output c_out; 
    	 
    submodules:


        N1: Nl {
            nl_id = address;

            @display("p=78,48");
        }

        N2: Dll1 {
            dll_id = address;

            @display("p=275,48");
        }
    
  
    	
    connections:
        N2.dlln_out --> N1.nl_in;
        N1.nl_out --> N2.dlln_in;
        N2.dllc_in <-- c_in ;
        N2.dllc_out --> c_out ;
       
        
}
