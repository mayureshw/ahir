-- $Header: /devl/xcs/repo/env/Databases/CAEInterfaces/vhdsclibs/data/unisims/unisim/VITAL/TOCBUF.vhd,v 1.1 2008/06/19 16:59:26 vandanad Exp $
-------------------------------------------------------------------------------
-- Copyright (c) 1995/2004 Xilinx, Inc.
-- All Right Reserved.
-------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor : Xilinx
-- \   \   \/     Version : 11.1
--  \   \         Description : Xilinx Functional Simulation Library Component
--  /   /                  Three-State on Configuration Buffer
-- /___/   /\     Filename : TOCBUF.vhd
-- \   \  /  \    Timestamp : Thu Apr  8 10:57:00 PDT 2004
--  \___\/\___\
--
-- Revision:
--    03/23/04 - Initial version.

----- CELL TOCBUF -----

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity TOCBUF is
  port(
    O : out std_ulogic;

    I : in std_ulogic
    );
end TOCBUF;

architecture TOCBUF_V of TOCBUF is
begin
  O <= I;
end TOCBUF_V;


