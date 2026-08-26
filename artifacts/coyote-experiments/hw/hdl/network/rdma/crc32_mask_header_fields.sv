import lynxTypes::*;

module crc32_mask_header_fields(
    // Networking interface - Incoming and outgoing traffic 
    AXI4S.m m_axis_rx, 
    AXI4S.m m_axis_tx, 

    // Incoming clock and reset
    input logic nclk, 
    input logic nresetn
);

// Definition of the one-mask 
logic [423:0] one_mask = 0;
//assign one_mask [3:0] = 0xF;
//assign one_mask [11:8] = 0xF;
//assign one_mask [31:12] = 0xFFFFF;
//assign one_mask [63:56] = 0xFF;
//assign one_mask [383:368] = 0xFFFF;
//assign one_mask [423:416] = 0xFF; 



endmodule