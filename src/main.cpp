/* --------------------------------------------------------------------------
Copyright 2012 by Richard Albrecht
richard.albrecht@rleofield.de
www.rleofield.de

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
------------------------------------------------------------------------------
*/


#include <iostream>
#include <iomanip>


#include "rimg_rgb_bgra_types.h"
#include "rimg_rgb_names.h"


using namespace rlf;


namespace {


   void demo_rgb( ) {

      std::vector<string> keys = tRGBtxt::keys();
      for( auto k: tRGBtxt::keys()){
         std::cout << k << std::endl;

      }

      std::cout << " lookup GreenYellow" << std::endl;
      tRGB rgb = tRGBtxt::lookup( X11_colors::GreenYellow );

      std::cout << " as open gl float" << std::endl;

      std::cout << rgb.gl_r() << std::endl;
      std::cout << rgb.gl_g() << std::endl;
      std::cout << rgb.gl_b() << std::endl;

      std::cout << " as int" << std::endl;

      uint32_t rr = rgb.r();
      std::cout << rr << std::endl;
      std::cout << static_cast<uint16_t>(rgb.g()) << std::endl;
      std::cout << static_cast<uint32_t>(rgb.b()) << std::endl;

      std::cout << " as printable char" << std::endl;
      std::cout << rgb.r() << std::endl;
      std::cout << rgb.g() << std::endl;
      std::cout << rgb.b() << std::endl;


      std::cout << std::endl;


   }



}



int main() {


   demo_rgb();


   return 0;
}

