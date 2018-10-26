------------------------------------------------------------------------------------------------
--
-- Copyright (C) 2010-: Madhav P. Desai
-- All Rights Reserved.
--  
-- Permission is hereby granted, free of charge, to any person obtaining a
-- copy of this software and associated documentation files (the
-- "Software"), to deal with the Software without restriction, including
-- without limitation the rights to use, copy, modify, merge, publish,
-- distribute, sublicense, and/or sell copies of the Software, and to
-- permit persons to whom the Software is furnished to do so, subject to
-- the following conditions:
-- 
--  * Redistributions of source code must retain the above copyright
--    notice, this list of conditions and the following disclaimers.
--  * Redistributions in binary form must reproduce the above
--    copyright notice, this list of conditions and the following
--    disclaimers in the documentation and/or other materials provided
--    with the distribution.
--  * Neither the names of the AHIR Team, the Indian Institute of
--    Technology Bombay, nor the names of its contributors may be used
--    to endorse or promote products derived from this Software
--    without specific prior written permission.
--
-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
-- OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
-- MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
-- IN NO EVENT SHALL THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR
-- ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
-- TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
-- SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE SOFTWARE.
------------------------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
library ahir;

use ahir.Types.all;
use ahir.subprograms.all;
use ahir.BaseComponents.all;
use ahir.utilities.all;


--
-- There is 0-delay path from 
--    req_in -> req_out.
--    req_in -> ack_out.
--    ack_in -> ack_out.
--
-- Because of these paths, the level-join is
-- to be used only in constructing level protocol
-- based pipelines.
--
entity generic_level_join is
  generic(name: string; num_reqs: integer)
  port ( req_in      : in   std_logic_vector(num_reqs-1 downto 0);
         ack_out     : out  std_logic_vector(num_reqs-1 downto 0);
    	 req_out : out  std_logic;
	 ack_in  : in   std_logic;
	 clk: in std_logic;
	 reset: in std_logic);
end generic_level_join;

architecture default_arch of generic_level_join is
  signal   req_out_sig: std_logic;
  constant const_one: std_logic_vector((num_reqs-1) downto 0) := (others => '1');
  constant const_zero: std_logic_vector((num_reqs-1) downto 0) := (others => '0');
begin  -- default_arch

  req_out_sig <= OrReduce(req_in);
  req_out <= req_out_sig;
  ack_out <= const_one when (req_out_sig = '1') and (ack_in = '1') else const_zero;
  
end default_arch;
