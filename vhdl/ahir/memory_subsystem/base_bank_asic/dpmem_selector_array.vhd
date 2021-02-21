------------------------------------------------------------------------------------------------
--
-- Copyright (C) 2010-: Madhav P. Desai, Ch. V. Kalyani
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
-------------------------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library ahir;
use ahir.Types.all;
use ahir.MemCutsPackage.all;
use ahir.mem_ASIC_components.all;
use ahir.MemcutDescriptionPackage.all;
use ahir.mem_component_pack.all;

entity dpmem_selector_array is
   generic ( name: string:="mem";
		 g_addr_width: natural := 5; 
	      	 g_data_width : natural := 20;
		 g_base_addr_width: natural := 5; 
	      	 g_base_data_width : natural := 20
	   );
   port (datain_0 : in std_logic_vector(g_data_width-1 downto 0);
         dataout_0: out std_logic_vector(g_data_width-1 downto 0);
         addrin_0: in std_logic_vector(g_addr_width-1 downto 0);
         enable_0: in std_logic;
         writebar_0 : in std_logic;
	 datain_1 : in std_logic_vector(g_data_width-1 downto 0);
         dataout_1: out std_logic_vector(g_data_width-1 downto 0);
         addrin_1: in std_logic_vector(g_addr_width-1 downto 0);
         enable_1: in std_logic;
         writebar_1 : in std_logic;
         clk: in std_logic;
         reset : in std_logic);
end entity;

architecture Struct of dpmem_selector_array is
	constant NCOLS : integer := (g_data_width/g_base_data_width);
begin
	assert((NCOLS*g_base_data_width) = g_data_width) report
		"In " & name & " g_data_width is not an exact multiple of g_base_data_width" 
			severity FAILURE;

	CGEN: for COL in 0 to NCOLS-1 generate
	     sel_inst: dpmem_column
		generic map (g_addr_width => g_addr_width,
				g_base_bank_addr_width => g_base_addr_width,
				g_base_bank_data_width => g_base_data_width)
			port map (
				datain_0  => datain_0(((COL+1)*g_base_data_width)-1 downto (COL*g_base_data_width)),
				dataout_0 => dataout_0(((COL+1)*g_base_data_width)-1 downto (COL*g_base_data_width)),
         			addrin_0 => addrin_0,
         			enable_0 => enable_0,
         			writebar_0 => writebar_0,
				datain_1  => datain_1(((COL+1)*g_base_data_width)-1 downto (COL*g_base_data_width)),
				dataout_1 => dataout_1(((COL+1)*g_base_data_width)-1 downto (COL*g_base_data_width)),
         			addrin_1 => addrin_1,
         			enable_1 => enable_1,
         			writebar_1 => writebar_1,
         			clk => clk,
         			reset => reset);
	end generate CGEN;
end Struct;

