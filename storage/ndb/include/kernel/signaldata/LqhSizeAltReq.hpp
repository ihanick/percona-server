/*
   Copyright (C) 2003, 2005, 2006 MySQL AB
    All rights reserved. Use is subject to license terms.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is also distributed with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have included with MySQL.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
*/

#ifndef LQH_SIZE_ALT_REQ_H
#define LQH_SIZE_ALT_REQ_H



#include "SignalData.hpp"

class LqhSizeAltReq {
  /**
   * Sender(s)
   */
  friend class ClusterConfiguration;

  /**
   * Reciver(s)
   */
  friend class Dblqh;
private:
  /**
   * Indexes in theData
   */
  STATIC_CONST( IND_BLOCK_REF     = 0);
  STATIC_CONST( IND_FRAG          = 1);
  STATIC_CONST( IND_CONNECT       = 2);
  STATIC_CONST( IND_TABLE         = 3);
  STATIC_CONST( IND_TC_CONNECT    = 4);
  STATIC_CONST( IND_REPLICAS      = 5);
  STATIC_CONST( IND_LOG_FILES     = 6);
  STATIC_CONST( IND_SCAN          = 7);
  
  /**
   * Use the index definitions to use the signal data
   */
  UintR theData[8];
};

#endif
