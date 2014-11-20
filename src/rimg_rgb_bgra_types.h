/*
--------------------------------------------------------------------------
Copyright 2013 by Richard Albrecht
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

C++, GCC
File: tRGB_BGRA.h
*/

#ifndef rlf_Colors_RGBA_H
#define rlf_Colors_RGBA_H

#include <string>
#include <vector>
#include <algorithm>


using std::string;
using std::vector;

namespace rlf {




   class tRGB {
      uint8_t _r;
      uint8_t _g;
      uint8_t _b;
      uint8_t _a;
      tRGB& operator+=( const tRGB& s );
      tRGB& operator-=( const tRGB& s );
      tRGB& operator*=( int d );

   public:

      tRGB(): _r( 0 ), _g( 0 ), _b( 0 ), _a( 255 ) {}
      tRGB( uint8_t r_, uint8_t g_, uint8_t b_ ): _r( r_ ), _g( g_ ), _b( b_ ), _a( 255 ) {}
      tRGB( uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_ ): _r( r_ ), _g( g_ ), _b( b_ ), _a( a_ ) {}
      ~tRGB() {}

      bool operator==( const tRGB& rgb )const {
         return rgb._r == _r && rgb._g == _g && rgb._b == _b && rgb._a == _a;
      }

      bool operator!=( const tRGB& s )const {
         return !( s == *this );
      }
      tRGB& operator=( const tRGB& rgb ) {
         if( this != &rgb ) {
            _r = rgb._r;
            _g = rgb._g;
            _b = rgb._b;
            _a = rgb._a;
         }

         return *this;
      }
      uint8_t& r() {
         return _r;
      }
      uint8_t& g() {
         return _g;
      }
      uint8_t& b() {
         return _b;
      }
      uint8_t& a() {
         return _a;
      }


      // GL
      float gl_r()const {
         return _r  / 255.0f;
      }
      float gl_g()const {
         return _g / 255.0f;
      }
      float gl_b()const {
         return _b / 255.0f;
      }
      float gl_a()const {
         return _a / 255.0f;
      }

      // CMYK, ohne Garantie, ob das so stimmt
      uint8_t k()const {
         return std::min( 255 - _r, std::min( 255 - _g, 255 - _b ) );
      }
      uint8_t c()const {
         return 255 * ( 255 - _r - k() ) / ( 255 - k() );
      }
      uint8_t m() const {
         return 255 * ( 255 - _g - k() ) / ( 255 - k() );
      }
      uint8_t y() const {
         return 255 * ( 255 - _b - k() ) / ( 255 - k() );
      }

   };


   class tRGBtxt: public tRGB {
      string _txt;
      static std::vector<string> _keys;
   public:
      tRGBtxt( uint8_t r, uint8_t g, uint8_t b, string const& t );
      string txt() const {
         return _txt;
      };
      static vector<tRGBtxt> rgb_txt;
      static vector<tRGBtxt> const& list() {
         return rgb_txt;
      }
      static vector<string> const& keys();
      static tRGB lookup( string const& k );
      ~tRGBtxt() {}
   };








}
#endif
//EOF
