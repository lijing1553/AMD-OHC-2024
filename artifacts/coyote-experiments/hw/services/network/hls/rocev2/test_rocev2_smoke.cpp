#include "rocev2.hpp"
#include "rocev2_config.hpp"
#include "../axi_utils.hpp"
#include "../ib_transport_protocol/ib_transport_protocol.hpp"

using namespace hls;

int main()
{
    stream<net_axis<DATA_WIDTH> > s_axis_rx_data("s_axis_rx_data");
    stream<net_axis<DATA_WIDTH> > m_axis_tx_data("m_axis_tx_data");
    stream<txMeta> s_axis_sq_meta("s_axis_sq_meta");
    stream<ackMeta> m_axis_rx_ack_meta("m_axis_rx_ack_meta");
    stream<memCmd> m_axis_mem_write_cmd("m_axis_mem_write_cmd");
    stream<memCmd> m_axis_mem_read_cmd("m_axis_mem_read_cmd");
    stream<net_axis<DATA_WIDTH> > m_axis_mem_write_data("m_axis_mem_write_data");
    stream<net_axis<DATA_WIDTH> > s_axis_mem_read_data("s_axis_mem_read_data");
    stream<qpContext> s_axis_qp_interface("s_axis_qp_interface");
    stream<ifConnReq> s_axis_qp_conn_interface("s_axis_qp_conn_interface");

    ap_uint<128> local_ip_address = 0;

    stream<ackEvent> tx_ackEvent_debug("tx_ackEvent_debug");
    stream<ap_uint<8> > tx_ibhHeaderFifo_debug("tx_ibhHeaderFifo_debug");
    stream<ap_uint<8> > tx_gibh_opcode_debug("tx_gibh_opcode_debug");
    stream<gibhPsnDebug> tx_gibh_psn_debug("tx_gibh_psn_debug");
    stream<ap_uint<8> > tx_pibh_opcode_debug("tx_pibh_opcode_debug");
    stream<event> tx_gexh_meta_debug("tx_gexh_meta_debug");
    stream<ap_uint<4> > tx_iumm_fire_debug("tx_iumm_fire_debug");
    stream<pibhDebug> tx_pibh_fire_debug("tx_pibh_fire_debug");
    stream<pibhDebug> tx_lrh_fire_debug("tx_lrh_fire_debug");
    stream<ibhFsmMeta> tx_ibhfsm_metain_debug("tx_ibhfsm_metain_debug");
    stream<ap_uint<4> > tx_gexh_state_debug("tx_gexh_state_debug");
    stream<ap_uint<4> > tx_gibh_state_debug("tx_gibh_state_debug");
    stream<ap_uint<24> > tx_iumm_dstQpFifo_debug("tx_iumm_dstQpFifo_debug");
    stream<ap_uint<16> > tx_exhfsm_qpn_debug("tx_exhfsm_qpn_debug");
    stream<intrusionDecision> intrusionDecisionIn("intrusionDecisionIn");
    stream<psnPkg> m_axis_dbg("m_axis_dbg");

    ap_uint<32> regCrcDropPkgCount = 0;
    ap_uint<32> regInvalidPsnDropCount = 0;
    ap_uint<32> regRetransCount = 0;
    ap_uint<32> regIbvCountRx = 0;
    ap_uint<32> regIbvCountTx = 0;

    rocev2<DATA_WIDTH>(
        s_axis_rx_data,
        m_axis_tx_data,
        s_axis_sq_meta,
        m_axis_rx_ack_meta,
        m_axis_mem_write_cmd,
        m_axis_mem_read_cmd,
        m_axis_mem_write_data,
        s_axis_mem_read_data,
        s_axis_qp_interface,
        s_axis_qp_conn_interface,
        local_ip_address,
        tx_ackEvent_debug,
        tx_ibhHeaderFifo_debug,
        tx_gibh_opcode_debug,
        tx_gibh_psn_debug,
        tx_pibh_opcode_debug,
        tx_gexh_meta_debug,
        tx_iumm_fire_debug,
        tx_pibh_fire_debug,
        tx_lrh_fire_debug,
        tx_ibhfsm_metain_debug,
        tx_gexh_state_debug,
        tx_gibh_state_debug,
        tx_iumm_dstQpFifo_debug,
        tx_exhfsm_qpn_debug,
        intrusionDecisionIn,
        regCrcDropPkgCount,
        regInvalidPsnDropCount,
        regRetransCount,
        regIbvCountRx,
        regIbvCountTx
    );

    return 0;
}
