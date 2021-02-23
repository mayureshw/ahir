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
--------------------------------------------------------------------------------------------------


library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

library ahir;
use ahir.mem_ASIC_components.all;

-- Entity to instantiate different available memory cuts based on the 
-- address_width and data_width generics passed.
entity dpmem_selector is
	generic(address_width: integer:=8; data_width: integer:=8);
	port (ADDR_0 : in std_logic_vector(address_width-1 downto 0 );
		ADDR_1 : in std_logic_vector(address_width-1 downto 0 );
		ENABLE_0_BAR : in std_logic;
		ENABLE_1_BAR : in std_logic;
		WRITE_0_BAR : in std_logic;
		WRITE_1_BAR : in std_logic;
		DATAIN_0  : in std_logic_vector(data_width-1 downto 0);
		DATAIN_1  : in std_logic_vector(data_width-1 downto 0);
		DATAOUT_0  : out std_logic_vector(data_width-1 downto 0);
		DATAOUT_1  : out std_logic_vector(data_width-1 downto 0);
		CLK, RESET: in std_logic);
end entity dpmem_selector;

architecture StructGen of dpmem_selector is
	signal TIE_HIGH, TIE_LOW: std_logic;
        signal TIE_LOW_3: std_logic_vector(2 downto 0);
        signal TIE_LOW_4: std_logic_vector(3 downto 0);
begin
	TIE_HIGH <= '1';
	TIE_LOW <= '0';
	TIE_LOW_3 <= (others => '0');
	TIE_LOW_4 <= (others => '0');
  SJKA65_32X128X1CM4_gen: if (address_width = 5) and (data_width = 128) generate
       inst: SJKA65_32X128X1CM4
   port map (A => ADDR_0, B => ADDR_1, CKA => CLK, CKB => CLK, WEAN => WRITE_0_BAR, WEBN => WRITE_1_BAR, DVSE => TIE_LOW, DVS => TIE_LOW_4, CSAN => ENABLE_0_BAR, CSBN => ENABLE_1_BAR, DIA => DATAIN_0, DIB => DATAIN_1, DOA => DATAOUT_0, DOB => DATAOUT_1);
  end generate SJKA65_32X128X1CM4_gen;
  SJKA65_64X2X1CM4_gen: if (address_width = 6) and (data_width = 2) generate
       inst: SJKA65_64X2X1CM4
   port map (A => ADDR_0, B => ADDR_1, CKA => CLK, CKB => CLK, WEAN => WRITE_0_BAR, WEBN => WRITE_1_BAR, DVSE => TIE_LOW, DVS => TIE_LOW_4, CSAN => ENABLE_0_BAR, CSBN => ENABLE_1_BAR, DIA => DATAIN_0, DIB => DATAIN_1, DOA => DATAOUT_0, DOB => DATAOUT_1);
  end generate SJKA65_64X2X1CM4_gen;
  SJKA65_64X4X1CM4_gen: if (address_width = 6) and (data_width = 4) generate
       inst: SJKA65_64X4X1CM4
   port map (A => ADDR_0, B => ADDR_1, CKA => CLK, CKB => CLK, WEAN => WRITE_0_BAR, WEBN => WRITE_1_BAR, DVSE => TIE_LOW, DVS => TIE_LOW_4, CSAN => ENABLE_0_BAR, CSBN => ENABLE_1_BAR, DIA => DATAIN_0, DIB => DATAIN_1, DOA => DATAOUT_0, DOB => DATAOUT_1);
  end generate SJKA65_64X4X1CM4_gen;
  SJKA65_64X8X1CM4_gen: if (address_width = 6) and (data_width = 8) generate
       inst: SJKA65_64X8X1CM4
   port map (A => ADDR_0, B => ADDR_1, CKA => CLK, CKB => CLK, WEAN => WRITE_0_BAR, WEBN => WRITE_1_BAR, DVSE => TIE_LOW, DVS => TIE_LOW_4, CSAN => ENABLE_0_BAR, CSBN => ENABLE_1_BAR, DIA => DATAIN_0, DIB => DATAIN_1, DOA => DATAOUT_0, DOB => DATAOUT_1);
  end generate SJKA65_64X8X1CM4_gen;
  SJKA65_64X16X1CM4_gen: if (address_width = 6) and (data_width = 16) generate
       inst: SJKA65_64X16X1CM4
   port map (A => ADDR_0, B => ADDR_1, CKA => CLK, CKB => CLK, WEAN => WRITE_0_BAR, WEBN => WRITE_1_BAR, DVSE => TIE_LOW, DVS => TIE_LOW_4, CSAN => ENABLE_0_BAR, CSBN => ENABLE_1_BAR, DIA => DATAIN_0, DIB => DATAIN_1, DOA => DATAOUT_0, DOB => DATAOUT_1);
  end generate SJKA65_64X16X1CM4_gen;
  SJKA65_256X4X1CM4_gen: if (address_width = 8) and (data_width = 4) generate
       inst: SJKA65_256X4X1CM4
   port map (A => ADDR_0, B => ADDR_1, CKA => CLK, CKB => CLK, WEAN => WRITE_0_BAR, WEBN => WRITE_1_BAR, DVSE => TIE_LOW, DVS => TIE_LOW_4, CSAN => ENABLE_0_BAR, CSBN => ENABLE_1_BAR, DIA => DATAIN_0, DIB => DATAIN_1, DOA => DATAOUT_0, DOB => DATAOUT_1);
  end generate SJKA65_256X4X1CM4_gen;
  SJKA65_256X16X1CM4_gen: if (address_width = 8) and (data_width = 16) generate
       inst: SJKA65_256X16X1CM4
   port map (A => ADDR_0, B => ADDR_1, CKA => CLK, CKB => CLK, WEAN => WRITE_0_BAR, WEBN => WRITE_1_BAR, DVSE => TIE_LOW, DVS => TIE_LOW_4, CSAN => ENABLE_0_BAR, CSBN => ENABLE_1_BAR, DIA => DATAIN_0, DIB => DATAIN_1, DOA => DATAOUT_0, DOB => DATAOUT_1);
  end generate SJKA65_256X16X1CM4_gen;
  SJKA65_256X32X1CM4_gen: if (address_width = 8) and (data_width = 32) generate
       inst: SJKA65_256X32X1CM4
   port map (A => ADDR_0, B => ADDR_1, CKA => CLK, CKB => CLK, WEAN => WRITE_0_BAR, WEBN => WRITE_1_BAR, DVSE => TIE_LOW, DVS => TIE_LOW_4, CSAN => ENABLE_0_BAR, CSBN => ENABLE_1_BAR, DIA => DATAIN_0, DIB => DATAIN_1, DOA => DATAOUT_0, DOB => DATAOUT_1);
  end generate SJKA65_256X32X1CM4_gen;
end StructGen;

