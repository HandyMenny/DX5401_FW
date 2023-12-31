#ifndef _ZCFG_RDM_OID_H
#define _ZCFG_RDM_OID_H

#define RDM_OID_DEVICE                           0 	/*Device*/
#define RDM_OID_SERVICE                          108	/*Device.Services*/
#define RDM_OID_VOICE_SRV                        144	/*Device.Services.VoiceService.i*/
#define RDM_OID_VOICE_CAPB                       228	/*Device.Services.VoiceService.i.Capabilities*/
#define RDM_OID_VOICE_CAPB_SIP                   1032	/*Device.Services.VoiceService.i.Capabilities.SIP*/
#define RDM_OID_VOICE_CAPB_MGCP                  1332	/*Device.Services.VoiceService.i.Capabilities.MGCP*/
#define RDM_OID_VOICE_CAPB_H323                  1392	/*Device.Services.VoiceService.i.Capabilities.H323*/
#define RDM_OID_VOICE_CAPB_CODEC                 1476	/*Device.Services.VoiceService.i.Capabilities.Codec.i*/
#define RDM_OID_VOICE_PROF                       1656	/*Device.Services.VoiceService.i.VoiceProfile.i*/
#define RDM_OID_VOICE_PROF_SRV_PRO_INFO          2844	/*Device.Services.VoiceService.i.VoiceProfile.i.ServiceProviderInfo*/
#define RDM_OID_VOICE_PROF_SIP                   2976	/*Device.Services.VoiceService.i.VoiceProfile.i.SIP*/
#define RDM_OID_VOICE_PROF_SIP_SUBSCRIBE_OBJ     4764	/*Device.Services.VoiceService.i.VoiceProfile.i.SIP.EventSubscribe.i*/
#define RDM_OID_VOICE_PROF_SIP_RESP_MAP_OBJ      4920	/*Device.Services.VoiceService.i.VoiceProfile.i.SIP.ResponseMap.i*/
#define RDM_OID_VOICE_PROF_RTP                   5028	/*Device.Services.VoiceService.i.VoiceProfile.i.RTP*/
#define RDM_OID_VOICE_PROF_RTP_RTCP              5208	/*Device.Services.VoiceService.i.VoiceProfile.i.RTP.RTCP*/
#define RDM_OID_VOICE_PROF_RTP_SRTP              5316	/*Device.Services.VoiceService.i.VoiceProfile.i.RTP.SRTP*/
#define RDM_OID_VOICE_PROF_RTP_REDUNDANCY        5448	/*Device.Services.VoiceService.i.VoiceProfile.i.RTP.Redundancy*/
#define RDM_OID_VOICE_PROF_NUM_PLAN              5676	/*Device.Services.VoiceService.i.VoiceProfile.i.NumberingPlan*/
#define RDM_OID_VOICE_PROF_NUM_PLAN_PREFIX_INFO  5928	/*Device.Services.VoiceService.i.VoiceProfile.i.NumberingPlan.PrefixInfo.i*/
#define RDM_OID_VOICE_PROF_TONE                  6156	/*Device.Services.VoiceService.i.VoiceProfile.i.Tone*/
#define RDM_OID_VOICE_PROF_TONE_EVENT            6264	/*Device.Services.VoiceService.i.VoiceProfile.i.Tone.Event.i*/
#define RDM_OID_VOICE_PROF_TONE_DESCRIPTION      6348	/*Device.Services.VoiceService.i.VoiceProfile.i.Tone.Description.i*/
#define RDM_OID_VOICE_PROF_TONE_PATTERN          6552	/*Device.Services.VoiceService.i.VoiceProfile.i.Tone.Pattern.i*/
#define RDM_OID_VOICE_PROF_FAX_T38               6924	/*Device.Services.VoiceService.i.VoiceProfile.i.FaxT38*/
#define RDM_OID_VOICE_LINE                       7104	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i*/
#define RDM_OID_VOICE_LINE_SIP                   7476	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.SIP*/
#define RDM_OID_VOICE_LINE_SIP_EVENT_SUBS        7752	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.SIP.EventSubscribe.i*/
#define RDM_OID_VOICE_LINE_RINGER                7860	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.Ringer*/
#define RDM_OID_VOICE_LINE_RINGER_EVENT          7968	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.Ringer.Event.i*/
#define RDM_OID_VOICE_LINE_RINGER_DESCRIPTION    8052	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.Ringer.Description.i*/
#define RDM_OID_VOICE_LINE_RINGER_PATTERN        8208	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.Ringer.Pattern.i*/
#define RDM_OID_VOICE_LINE_CALLING_FEATURE       8340	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.CallingFeatures*/
#define RDM_OID_VOICE_LINE_PROCESSING            9840	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.VoiceProcessing*/
#define RDM_OID_VOICE_LINE_CODEC                 10140	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.Codec*/
#define RDM_OID_VOICE_LINE_CODEC_LIST            10344	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.Codec.List.i*/
#define RDM_OID_VOICE_LINE_SESSION               10620	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.Session.i*/
#define RDM_OID_VOICE_LINE_STATS                 10776	/*Device.Services.VoiceService.i.VoiceProfile.i.Line.i.Stats*/
#define RDM_OID_VOICE_PHY_INTF                   11556	/*Device.Services.VoiceService.i.PhyInterface.i*/
#define RDM_OID_VOICE_FXS_CID                    12216	/*Device.Services.VoiceService.i.PhyInterface.i.X_ZYXEL_CID*/
#define RDM_OID_VOICE_PSTN                       12300	/*Device.Services.VoiceService.i.X_ZYXEL_PSTN.i*/
#define RDM_OID_VOICE_COMMON                     12480	/*Device.Services.VoiceService.i.X_ZYXEL_Common*/
#define RDM_OID_VOICE_PHONE_BOOK                 13068	/*Device.Services.VoiceService.i.X_ZYXEL_VoicePhoneBook*/
#define RDM_OID_SPEED_DIAL_BOOK                  13104	/*Device.Services.VoiceService.i.X_ZYXEL_VoicePhoneBook.SpeedDialBook*/
#define RDM_OID_SPEED_DIAL_BOOK_LIST             13164	/*Device.Services.VoiceService.i.X_ZYXEL_VoicePhoneBook.SpeedDialBook.List.i*/
#define RDM_OID_CALL_POLICY_BOOK                 13344	/*Device.Services.VoiceService.i.X_ZYXEL_VoicePhoneBook.CallPolicyBook*/
#define RDM_OID_CALL_POLICY_BOOK_LIST            13548	/*Device.Services.VoiceService.i.X_ZYXEL_VoicePhoneBook.CallPolicyBook.List.i*/
#define RDM_OID_VOICE_INTERNAL_PHONE_NUMBER_BOOK 13728	/*Device.Services.VoiceService.i.X_ZYXEL_VoicePhoneBook.InternalPhoneNumberBook*/
#define RDM_OID_VOICE_INTERNAL_PHONE_NUMBER_BOOK_IF_LIST 13788	/*Device.Services.VoiceService.i.X_ZYXEL_VoicePhoneBook.InternalPhoneNumberBook.InterfaceList.i*/
#define RDM_OID_VOICE_INTERNAL_PHONE_NUMBER_BOOK_PORT_LIST 13872	/*Device.Services.VoiceService.i.X_ZYXEL_VoicePhoneBook.InternalPhoneNumberBook.InterfaceList.i.PortList.i*/
#define RDM_OID_VOICE_FXO                        13932	/*Device.Services.VoiceService.i.X_ZYXEL_FXO*/
#define RDM_OID_VOICE_FXO_PORT                   13992	/*Device.Services.VoiceService.i.X_ZYXEL_FXO.Port.i*/
#define RDM_OID_VOICE_CALL_STATUS                14268	/*Device.Services.VoiceService.i.X_ZYXEL_CALL_STATUS*/
#define RDM_OID_MGMT_SRV                         14496	/*Device.ManagementServer*/
#define RDM_OID_MGMT_SRV_MGAB_DEV                16668	/*Device.ManagementServer.ManageableDevice.i*/
#define RDM_OID_MGMT_SRV_AUTO_TRANS_COMPLETE_POL 16872	/*Device.ManagementServer.AutonomousTransferCompletePolicy*/
#define RDM_OID_MGMT_SRV_DL_AVAIL                17004	/*Device.ManagementServer.DownloadAvailability*/
#define RDM_OID_MGMT_SRV_DL_AVAIL_ANNCMNT        17040	/*Device.ManagementServer.DownloadAvailability.Announcement*/
#define RDM_OID_MGMT_SRV_DL_AVAIL_ANNCMNT_GROUP  17148	/*Device.ManagementServer.DownloadAvailability.Announcement.Group.i*/
#define RDM_OID_MGMT_SRV_DL_AVAIL_QUERY          17280	/*Device.ManagementServer.DownloadAvailability.Query*/
#define RDM_OID_MGMT_SRV_DU_STATE_CHANGE_COMPL_POL 17388	/*Device.ManagementServer.DUStateChangeComplPolicy*/
#define RDM_OID_MGMT_SRV_EMBEDED_DEV             17520	/*Device.ManagementServer.EmbeddedDevice.i*/
#define RDM_OID_MGMT_SRV_VIRTUAL_DEV             17772	/*Device.ManagementServer.VirtualDevice.i*/
#define RDM_OID_MGMT_SRV_INFORM_PAR              17928	/*Device.ManagementServer.InformParameter.i*/
#define RDM_OID_TIME                             18060	/*Device.Time*/
#define RDM_OID_USR_INTF                         18720	/*Device.UserInterface*/
#define RDM_OID_USR_INTF_REMO_ACESS              19356	/*Device.UserInterface.RemoteAccess*/
#define RDM_OID_USR_INTF_LOCAL_DISP              19488	/*Device.UserInterface.LocalDisplay*/
#define RDM_OID_IFACE_STACK                      19716	/*Device.InterfaceStack.i*/
#define RDM_OID_ETH                              19872	/*Device.Ethernet*/
#define RDM_OID_ETH_RMON_ST                      20004	/*Device.Ethernet.RMONStats.i*/
#define RDM_OID_ETH_IFACE                        20568	/*Device.Ethernet.Interface.i*/
#define RDM_OID_ETH_INTF_ST                      21156	/*Device.Ethernet.Interface.i.Stats*/
#define RDM_OID_ETH_LINK                         21552	/*Device.Ethernet.Link.i*/
#define RDM_OID_ETH_LINK_ST                      21924	/*Device.Ethernet.Link.i.Stats*/
#define RDM_OID_ETH_VLAN_TERM                    22320	/*Device.Ethernet.VLANTermination.i*/
#define RDM_OID_ETH_VLAN_TERM_ST                 22668	/*Device.Ethernet.VLANTermination.i.Stats*/
#define RDM_OID_BRIDGING                         23064	/*Device.Bridging*/
#define RDM_OID_BRIDGING_BR                      23340	/*Device.Bridging.Bridge.i*/
#define RDM_OID_BRIDGING_BR_PORT                 23664	/*Device.Bridging.Bridge.i.Port.i*/
#define RDM_OID_BRIDGING_BR_PORT_ST              24180	/*Device.Bridging.Bridge.i.Port.i.Stats*/
#define RDM_OID_BRIDGING_BR_VLAN                 24576	/*Device.Bridging.Bridge.i.VLAN.i*/
#define RDM_OID_BRIDGING_BR_VLANPORT             24708	/*Device.Bridging.Bridge.i.VLANPort.i*/
#define RDM_OID_BRIDGING_FILTER                  24864	/*Device.Bridging.Filter.i*/
#define RDM_OID_PPP                              25716	/*Device.PPP*/
#define RDM_OID_PPP_IFACE                        25800	/*Device.PPP.Interface.i*/
#define RDM_OID_PPP_IFACE_PPPOA                  26868	/*Device.PPP.Interface.i.PPPoA*/
#define RDM_OID_PPP_IFACE_PPPOE                  26904	/*Device.PPP.Interface.i.PPPoE*/
#define RDM_OID_PPP_IFACE_IPCP                   27036	/*Device.PPP.Interface.i.IPCP*/
#define RDM_OID_PPP_INTF_IPV6CP                  27192	/*Device.PPP.Interface.i.IPV6CP*/
#define RDM_OID_PPP_IFACE_STAT                   27276	/*Device.PPP.Interface.i.Stats*/
#define RDM_OID_IP                               27672	/*Device.IP*/
#define RDM_OID_IP_IFACE                         27924	/*Device.IP.Interface.i*/
#define RDM_OID_IP_IFACE_V4_ADDR                 29664	/*Device.IP.Interface.i.IPv4Address.i*/
#define RDM_OID_IP_IFACE_V6_ADDR                 29916	/*Device.IP.Interface.i.IPv6Address.i*/
#define RDM_OID_IP_IFACE_V6_PREFIX               30288	/*Device.IP.Interface.i.IPv6Prefix.i*/
#define RDM_OID_IP_IFACE_STAT                    30732	/*Device.IP.Interface.i.Stats*/
#define RDM_OID_IP_ACTIVE_PORT                   31128	/*Device.IP.ActivePort.i*/
#define RDM_OID_IP_DIAG                          31284	/*Device.IP.Diagnostics*/
#define RDM_OID_IP_DIAG_IPPING                   31512	/*Device.IP.Diagnostics.IPPing*/
#define RDM_OID_IP_DIAG_TRACE_RT                 31956	/*Device.IP.Diagnostics.TraceRoute*/
#define RDM_OID_IP_DIAG_TRACERT_RT_HOPS          32280	/*Device.IP.Diagnostics.TraceRoute.RouteHops.i*/
#define RDM_OID_IP_DIAG_DL_DIAG                  32412	/*Device.IP.Diagnostics.DownloadDiagnostics*/
#define RDM_OID_IP_DIAG_DL_DIAG_PER_CONN_RST     33552	/*Device.IP.Diagnostics.DownloadDiagnostics.PerConnectionResult.i*/
#define RDM_OID_IP_DIAG_DL_DIAG_INCREM_RST       33780	/*Device.IP.Diagnostics.DownloadDiagnostics.IncrementalResult.i*/
#define RDM_OID_IP_DIAG_UL_DIAG                  33936	/*Device.IP.Diagnostics.UploadDiagnostics*/
#define RDM_OID_IP_DIAG_UL_DIAG_PER_CONN_RST     35100	/*Device.IP.Diagnostics.UploadDiagnostics.PerConnectionResult.i*/
#define RDM_OID_IP_DIAG_UL_DIAG_INCREM_RST       35328	/*Device.IP.Diagnostics.UploadDiagnostics.IncrementalResult.i*/
#define RDM_OID_IP_DIAG_UDP_ECHO_CFG             35484	/*Device.IP.Diagnostics.UDPEchoConfig*/
#define RDM_OID_IP_DIAG_UDP_ECHO_DIAG            35808	/*Device.IP.Diagnostics.UDPEchoDiagnostics*/
#define RDM_OID_IP_DIAG_UDP_ECHO_PAK_RST         36324	/*Device.IP.Diagnostics.UDPEchoDiagnostics.IndividualPacketResult.i*/
#define RDM_OID_IP_DIAG_SVR_SELECT_DIAG          36552	/*Device.IP.Diagnostics.ServerSelectionDiagnostics*/
#define RDM_OID_IP_DIAG_CAPABILITIES             36876	/*Device.IP.Diagnostics.Capabilities*/
#define RDM_OID_IP_DIAG_CAP_PERF_DIAG            36912	/*Device.IP.Diagnostics.Capabilities.PerformanceDiagnostic*/
#define RDM_OID_MAP                              37116	/*Device.MAP*/
#define RDM_OID_MAP_DOMAIN                       37200	/*Device.MAP.Domain.i*/
#define RDM_OID_MAP_DOMAIN_RULE                  37572	/*Device.MAP.Domain.i.Rule.i*/
#define RDM_OID_MAP_DOMAIN_IFACE                 37872	/*Device.MAP.Domain.i.Interface*/
#define RDM_OID_MAP_DOMAIN_IFACE_STAT            38052	/*Device.MAP.Domain.i.Interface.Stats*/
#define RDM_OID_CAPT_PORTAL                      38448	/*Device.CaptivePortal*/
#define RDM_OID_ROUTING                          38580	/*Device.Routing*/
#define RDM_OID_ROUTING_ROUTER                   38640	/*Device.Routing.Router.i*/
#define RDM_OID_ROUTING_ROUTER_V4_FWD            38868	/*Device.Routing.Router.i.IPv4Forwarding.i*/
#define RDM_OID_ROUTING_ROUTER_V6_FWD            39384	/*Device.Routing.Router.i.IPv6Forwarding.i*/
#define RDM_OID_ROUTING_RIP                      39660	/*Device.Routing.RIP*/
#define RDM_OID_ROUTING_RIP_INTF_SET             39768	/*Device.Routing.RIP.InterfaceSetting.i*/
#define RDM_OID_ROUTING_RT_INFO                  40020	/*Device.Routing.RouteInformation*/
#define RDM_OID_ROUTING_RT_INFO_INTF_SET         40104	/*Device.Routing.RouteInformation.InterfaceSetting.i*/
#define RDM_OID_V4_ROUTING_TABLE                 40380	/*Device.Routing.X_ZYXEL_IPV4RoutingTable.i*/
#define RDM_OID_V6_ROUTING_TABLE                 40560	/*Device.Routing.X_ZYXEL_IPV6RoutingTable.i*/
#define RDM_OID_NEIGHBOR_DISCOVERY               40716	/*Device.NeighborDiscovery*/
#define RDM_OID_RT_ADV                           40800	/*Device.RouterAdvertisement*/
#define RDM_OID_RT_ADV_INTF_SET                  40884	/*Device.RouterAdvertisement.InterfaceSetting.i*/
#define RDM_OID_IPV6RD                           41472	/*Device.IPv6rd*/
#define RDM_OID_IPV6RD_INTF                      41556	/*Device.IPv6rd.InterfaceSetting.i*/
#define RDM_OID_DS_LITE                          41856	/*Device.DSLite*/
#define RDM_OID_DS_LITE_INTF_SET                 41940	/*Device.DSLite.InterfaceSetting.i*/
#define RDM_OID_LAN_CONF_SEC                     42288	/*Device.LANConfigSecurity*/
#define RDM_OID_HOSTS                            42348	/*Device.Hosts*/
#define RDM_OID_HOSTS_HOST                       42456	/*Device.Hosts.Host.i*/
#define RDM_OID_HOSTS_HOST_V4_ADDR               43428	/*Device.Hosts.Host.i.IPv4Address.i*/
#define RDM_OID_HOSTS_HOST_V6_ADDR               43488	/*Device.Hosts.Host.i.IPv6Address.i*/
#define RDM_OID_ZY_HOSTS_HOST_EXT                43548	/*Device.Hosts.Host.i.X_ZYXEL_EXT*/
#define RDM_OID_DNS                              43848	/*Device.DNS*/
#define RDM_OID_DNS_CLIENT                       44004	/*Device.DNS.Client*/
#define RDM_OID_DNS_CLIENT_SRV                   44136	/*Device.DNS.Client.Server.i*/
#define RDM_OID_DNS_DIAG                         44436	/*Device.DNS.Diagnostics*/
#define RDM_OID_DNS_DIAG_NS_LOOKUP_DIAG          44472	/*Device.DNS.Diagnostics.NSLookupDiagnostics*/
#define RDM_OID_DNS_DIAG_NS_LOOKUP_DIAG_RESULT   44724	/*Device.DNS.Diagnostics.NSLookupDiagnostics.Result.i*/
#define RDM_OID_NAT                              44904	/*Device.NAT*/
#define RDM_OID_NAT_INTF_SETTING                 45180	/*Device.NAT.InterfaceSetting.i*/
#define RDM_OID_NAT_PORT_MAPPING                 45336	/*Device.NAT.PortMapping.i*/
#define RDM_OID_NAT_PORT_TRIGGERING              45900	/*Device.NAT.X_ZYXEL_PortTriggering.i*/
#define RDM_OID_NAT_ADDR_MAPPING                 46224	/*Device.NAT.X_ZYXEL_AddrMapping.i*/
#define RDM_OID_NAT_SESSION_CTL                  46548	/*Device.NAT.X_ZYXEL_SessionControl*/
#define RDM_OID_NAT_PORT_CONTROL                 46776	/*Device.NAT.X_ZYXEL_PCP.i*/
#define RDM_OID_DHCPV4                           47196	/*Device.DHCPv4*/
#define RDM_OID_DHCPV4_CLIENT                    47256	/*Device.DHCPv4.Client.i*/
#define RDM_OID_DHCPV4_SENT_OPT                  47796	/*Device.DHCPv4.Client.i.SentOption.i*/
#define RDM_OID_DHCPV4_REQ_OPT                   47928	/*Device.DHCPv4.Client.i.ReqOption.i*/
#define RDM_OID_DHCPV4_SRV                       48084	/*Device.DHCPv4.Server*/
#define RDM_OID_DHCPV4_SRV_POOL                  48216	/*Device.DHCPv4.Server.Pool.i*/
#define RDM_OID_DHCPV4_SRV_POOL_STATIC_ADDR      49068	/*Device.DHCPv4.Server.Pool.i.StaticAddress.i*/
#define RDM_OID_DHCPV4_SRV_POOL_OPT              49200	/*Device.DHCPv4.Server.Pool.i.Option.i*/
#define RDM_OID_DHCPV4_SRV_POOL_CLIENT           49356	/*Device.DHCPv4.Server.Pool.i.Client.i*/
#define RDM_OID_DHCPV4_SRV_POOL_CLIENT_V4_ADDR   49512	/*Device.DHCPv4.Server.Pool.i.Client.i.IPv4Address.i*/
#define RDM_OID_DHCPV4_SRV_POOL_CLIENT_OPT       49596	/*Device.DHCPv4.Server.Pool.i.Client.i.Option.i*/
#define RDM_OID_DHCPV4_SRV_SUBNET                49680	/*Device.DHCPv4.Server.X_ZYXEL_Subnet.i*/
#define RDM_OID_DHCPV4_RELAY                     49860	/*Device.DHCPv4.Relay*/
#define RDM_OID_DHCPV4_RELAY_FWD                 49992	/*Device.DHCPv4.Relay.Forwarding.i*/
#define RDM_OID_DHCPV6                           50436	/*Device.DHCPv6*/
#define RDM_OID_DHCPV6_CLIENT                    50496	/*Device.DHCPv6.Client.i*/
#define RDM_OID_DHCPV6_CLIENT_SRV                50988	/*Device.DHCPv6.Client.i.Server.i*/
#define RDM_OID_DHCPV6_CLIENT_SENT_OPT           51096	/*Device.DHCPv6.Client.i.SentOption.i*/
#define RDM_OID_DHCPV6_CLIENT_RECEIVED_OPT       51228	/*Device.DHCPv6.Client.i.ReceivedOption.i*/
#define RDM_OID_DHCPV6_SRV                       51336	/*Device.DHCPv6.Server*/
#define RDM_OID_DHCPV6_SRV_POOL                  51420	/*Device.DHCPv6.Server.Pool.i*/
#define RDM_OID_DHCPV6_SRV_POOL_CLIENT           52176	/*Device.DHCPv6.Server.Pool.i.Client.i*/
#define RDM_OID_DHCPV6_SRV_POOL_CLIENT_V6_ADDR   52356	/*Device.DHCPv6.Server.Pool.i.Client.i.IPv6Address.i*/
#define RDM_OID_DHCPV6_SRV_POOL_CLIENT_V6_PREFIX 52464	/*Device.DHCPv6.Server.Pool.i.Client.i.IPv6Prefix.i*/
#define RDM_OID_DHCPV6_SRV_POOL_CLIENT_OPT       52572	/*Device.DHCPv6.Server.Pool.i.Client.i.Option.i*/
#define RDM_OID_DHCPV6_SRV_POOL_OPT              52656	/*Device.DHCPv6.Server.Pool.i.Option.i*/
#define RDM_OID_IEEE8021X                        52812	/*Device.IEEE8021x*/
#define RDM_OID_IEEE8021X_SUPPLICANT             52872	/*Device.IEEE8021x.Supplicant.i*/
#define RDM_OID_IEEE8021X_SUPPLICANT_STAT        53340	/*Device.IEEE8021x.Supplicant.i.Stats*/
#define RDM_OID_IEEE8021X_SUPPLICANT_EAPMD5      53640	/*Device.IEEE8021x.Supplicant.i.EAPMD5*/
#define RDM_OID_IEEE8021X_SUPPLICANT_EAPTLS      53724	/*Device.IEEE8021x.Supplicant.i.EAPTLS*/
#define RDM_OID_USRS                             53808	/*Device.Users*/
#define RDM_OID_USRS_USR                         53868	/*Device.Users.User.i*/
#define RDM_OID_SELF_TEST_DIAG                   54048	/*Device.SelfTestDiagnostics*/
#define RDM_OID_FIREWALL                         54132	/*Device.Firewall*/
#define RDM_OID_FIREWALL_LEVEL                   54456	/*Device.Firewall.Level.i*/
#define RDM_OID_FIREWALL_CHAIN                   54708	/*Device.Firewall.Chain.i*/
#define RDM_OID_FIREWALL_CHAIN_RULE              54864	/*Device.Firewall.Chain.i.Rule.i*/
#define RDM_OID_DEV_SEC                          55980	/*Device.Security*/
#define RDM_OID_DEV_SEC_CERT                     56040	/*Device.Security.Certificate.i*/
#define RDM_OID_ROM_CONVERT                      56508	/*Device.X_ZYXEL_RomConvert.i*/
#define RDM_OID_EMAIL_NOTIFY                     56568	/*Device.X_ZYXEL_EmailNotification*/
#define RDM_OID_MAIL_SERVICE                     56604	/*Device.X_ZYXEL_EmailNotification.EmailService.i*/
#define RDM_OID_MAIL_EVENT_CFG                   56832	/*Device.X_ZYXEL_EmailNotification.EmailEventConfig.i*/
#define RDM_OID_PAREN_CTL                        57012	/*Device.X_ZYXEL_ParentalControl*/
#define RDM_OID_PAREN_CTL_PROF                   57072	/*Device.X_ZYXEL_ParentalControl.Profile.i*/
#define RDM_OID_IEEE8021AG                       57444	/*Device.X_ZYXEL_8021ag*/
#define RDM_OID_IEEE8023AH                       57936	/*Device.X_ZYXEL_8023ah*/
#define RDM_OID_ZY_EXT                           58188	/*Device.X_ZYXEL_EXT*/
#define RDM_OID_DNS_RT_ENTRY                     58368	/*Device.X_ZYXEL_EXT.DNSRouteEntry.i*/
#define RDM_OID_DNS_ENTRY                        58620	/*Device.X_ZYXEL_EXT.DNSEntry.i*/
#define RDM_OID_D_DNS                            58704	/*Device.X_ZYXEL_EXT.DynamicDNS*/
#define RDM_OID_AUTO_PROV                        59124	/*Device.X_ZYXEL_EXT.AutoProvision*/
#define RDM_OID_ZY_HOST_NAME_REPLACE             59352	/*Device.X_ZYXEL_EXT.HostNameReplace*/
#define RDM_OID_VPN_CFG                          59412	/*Device.X_ZYXEL_EXT.X_ZYXEL_VPN*/
#define RDM_OID_VPN_CLIENT_CFG                   59472	/*Device.X_ZYXEL_EXT.X_ZYXEL_VPN.X_ZYXEL_VPNClient_Config.i*/
#define RDM_OID_EOGRE_CFG                        59820	/*Device.X_ZYXEL_EXT.X_ZYXEL_EoGRE_Config*/
#define RDM_OID_LAN_DEV                          60000	/*Device.X_ZYXEL_EXT.LANDevice.i*/
#define RDM_OID_DATA_ELEMENT                     60108	/*Device.X_ZYXEL_EXT.DataElement*/
#define RDM_OID_MAC_ADDRESS_TABLE                60168	/*Device.X_ZYXEL_EXT.MacAddressTable*/
#define RDM_OID_LINK_QUALITY                     60372	/*Device.X_ZYXEL_EXT.LinkQuality*/
#define RDM_OID_WPS_BUTTON_PRESS                 60480	/*Device.X_ZYXEL_EXT.WpsButtonPress*/
#define RDM_OID_REBOOT_SCHEDULE                  60612	/*Device.X_ZYXEL_EXT.RebootSchedule*/
#define RDM_OID_EASY_MESH                        60792	/*Device.X_ZYXEL_EXT.EasyMesh*/
#define RDM_OID_EASY_MESH_TS                     60996	/*Device.X_ZYXEL_EXT.EasyMesh.EasyMeshTs*/
#define RDM_OID_ZY_IGMP                          61104	/*Device.X_ZYXEL_IGMP*/
#define RDM_OID_ZY_IGMP_D_ACL                    61620	/*Device.X_ZYXEL_IGMP.DynamicACLTable.i*/
#define RDM_OID_DEV_SNOOP_TABLE                  61728	/*Device.X_ZYXEL_IGMP.SNOOP_TABLE.i*/
#define RDM_OID_DEV_MCST_TABLE                   61884	/*Device.X_ZYXEL_IGMP.MCAST_TABLE.i*/
#define RDM_OID_ZY_MLD                           61992	/*Device.X_ZYXEL_MLD*/
#define RDM_OID_ZY_LOG_CFG                       62412	/*Device.X_ZYXEL_LoginCfg*/
#define RDM_OID_ZY_LOG_CFG_GP                    62544	/*Device.X_ZYXEL_LoginCfg.LogGp.i*/
#define RDM_OID_ZY_LOG_CFG_GP_ACCOUNT            62724	/*Device.X_ZYXEL_LoginCfg.LogGp.i.Account.i*/
#define RDM_OID_ZY_MAC_FILTER                    63600	/*Device.X_ZYXEL_MacFilter*/
#define RDM_OID_ZY_MAC_FILTER_WHITE_LIST         63708	/*Device.X_ZYXEL_MacFilter.WhiteList.i*/
#define RDM_OID_ZY_IP_FILTER                     63816	/*Device.X_ZYXEL_IpFilter*/
#define RDM_OID_ZY_IP_FILTER_WHITE_LIST          63924	/*Device.X_ZYXEL_IpFilter.WhiteList.i*/
#define RDM_OID_VLAN_AUTO_HUNT                   64032	/*Device.X_ZYXEL_VlanAutoHunt*/
#define RDM_OID_VLAN_HUNT_INFO                   64164	/*Device.X_ZYXEL_VlanAutoHunt.VlanHuntInfo.i*/
#define RDM_OID_VLAN_HUNT_RULE                   64248	/*Device.X_ZYXEL_VlanAutoHunt.VlanHuntInfo.i.VlanHuntRule.i*/
#define RDM_OID_LANG                             64332	/*Device.X_ZYXEL_Language*/
#define RDM_OID_REMO_MGMT                        64392	/*Device.X_ZYXEL_RemoteManagement*/
#define RDM_OID_REMO_SRV                         64572	/*Device.X_ZYXEL_RemoteManagement.Service.i*/
#define RDM_OID_REMO_SRV_TRUST_DOMAIN            64896	/*Device.X_ZYXEL_RemoteManagement.Service.i.TrustDomain.i*/
#define RDM_OID_SP_REMO_SRV                      65004	/*Device.X_ZYXEL_RemoteManagement.SPService.i*/
#define RDM_OID_SP_REMO_SRV_TRUST_DOMAIN         65304	/*Device.X_ZYXEL_RemoteManagement.SPService.i.TrustDomain.i*/
#define RDM_OID_REMO_MGMT_TRUST_DOMAIN           65436	/*Device.X_ZYXEL_RemoteManagement.TrustDomain.i*/
#define RDM_OID_SP_TRUST_DOMAIN                  65544	/*Device.X_ZYXEL_RemoteManagement.SPTrustDomain.i*/
#define RDM_OID_INTERFACE_TRUST_DOMAIN           65676	/*Device.X_ZYXEL_RemoteManagement.InterfaceTrustDomain.i*/
#define RDM_OID_INTERFACE_TRUST_DOMAIN_INFO      65760	/*Device.X_ZYXEL_RemoteManagement.InterfaceTrustDomain.i.TrustDomainInfo.i*/
#define RDM_OID_M_PRO_MESH_APP                   65868	/*Device.X_ZYXEL_RemoteManagement.MProMeshApp*/
#define RDM_OID_NETWORK_SRV                      65928	/*Device.X_ZYXEL_NetworkService*/
#define RDM_OID_NETWORK_SRV_GP                   65988	/*Device.X_ZYXEL_NetworkService.Service.i*/
#define RDM_OID_SYSTEM_INFO                      66240	/*Device.X_ZYXEL_System_Info*/
#define RDM_OID_LOG_SETTING                      66516	/*Device.X_ZYXEL_Log_Setting*/
#define RDM_OID_LOG_CLASSIFY                     66768	/*Device.X_ZYXEL_Log_Setting.LogClassify.i*/
#define RDM_OID_LOG_CATEGORY                     66900	/*Device.X_ZYXEL_Log_Setting.LogClassify.i.Category.i*/
#define RDM_OID_CHANGE_ICON_NAME                 67080	/*Device.X_ZYXEL_Change_Icon_Name.i*/
#define RDM_OID_PORT_MIRROR                      67476	/*Device.X_ZYXEL_PortMirroring.i*/
#define RDM_OID_TR064                            67680	/*Device.X_ZYXEL_TR064*/
#define RDM_OID_ACL                              67860	/*Device.X_ZYXEL_TR064.ACL*/
#define RDM_OID_CONTROL_POINT                    67896	/*Device.X_ZYXEL_TR064.ACL.CP.i*/
#define RDM_OID_ACTIONS                          68028	/*Device.X_ZYXEL_TR064.ACL.Actions.i*/
#define RDM_OID_GUI_CUSTOMIZATION                68136	/*Device.X_ZYXEL_GUI_CUSTOMIZATION*/
#define RDM_OID_INPUT_CHECK_LIST                 68628	/*Device.X_ZYXEL_GUI_CUSTOMIZATION.InputCheckList.i*/
#define RDM_OID_FEATURE_FLAG                     68808	/*Device.X_ZYXEL_FEATRUE_FLAG*/
#define RDM_OID_INIT_FLAG                        69468	/*Device.X_ZYXEL_INIT_FLAG*/
#define RDM_OID_ZY_OPTION125                     69552	/*Device.X_ZYXEL_Option125VendorSpecific*/
#define RDM_OID_ZY_VENDOR_SPECIFIC               69612	/*Device.X_ZYXEL_Option125VendorSpecific.VendorSpecific.i*/
#define RDM_OID_INTERNAL_DATA                    69744	/*Device.X_ZYXEL_InternalData*/
#define RDM_OID_ONLINE_F_W_UPGRADE               69804	/*Device.X_ZYXEL_Online_FW_Upgrade*/
#define RDM_OID_LANDING_PAGE                     70056	/*Device.X_ZYXEL_Landing_Page*/
#define RDM_OID_ZY_RESET_ADMIN                   70140	/*Device.X_ZYXEL_RESET_ADMIN*/
#define RDM_OID_CRONTAB                          70200	/*Device.X_ZYXEL_Crontab*/
#define RDM_OID_IPERF                            70260	/*Device.X_ZYXEL_Iperf*/
#define RDM_OID_CONTENT_FILTER                   70392	/*Device.X_ZYXEL_ContentFilter.i*/
#define RDM_OID_SYSTEM_DEBUG                     70884	/*Device.X_ZYXEL_System_Debug*/
#define RDM_OID_VLAN_GROUP                       71040	/*Device.X_ZYXEL_VlanGroup.i*/
#define RDM_OID_SPEED_TEST                       71220	/*Device.SpeedTestInfo*/
#define RDM_OID_ZLOG_CONFIG                      71400	/*Device.X_ZYXEL_Zlog_Setting*/
#define RDM_OID_ZLOG_CATEGORY                    71484	/*Device.X_ZYXEL_Zlog_Setting.ZlogCategory.i*/
#define RDM_OID_ZY_SAMBA                         71832	/*Device.X_ZYXEL_SAMBA*/
#define RDM_OID_ZY_SAMBA_DIR                     71988	/*Device.X_ZYXEL_SAMBA.Directory.i*/
#define RDM_OID_DEV_INFO                         72240	/*Device.DeviceInfo*/
#define RDM_OID_DEV_INFO_VEND_CONF_FILE          72924	/*Device.DeviceInfo.VendorConfigFile.i*/
#define RDM_OID_DEV_INFO_SUP_DATA_MODEL          73080	/*Device.DeviceInfo.SupportedDataModel.i*/
#define RDM_OID_DEV_INFO_MEM_STAT                73212	/*Device.DeviceInfo.MemoryStatus*/
#define RDM_OID_DEV_INFO_PS_STAT                 73296	/*Device.DeviceInfo.ProcessStatus*/
#define RDM_OID_DEV_INFO_PS_STAT_PS              73380	/*Device.DeviceInfo.ProcessStatus.Process.i*/
#define RDM_OID_TEMP_STAT                        73560	/*Device.DeviceInfo.TemperatureStatus*/
#define RDM_OID_TEMP_STAT_TEMP_SENSOR            73620	/*Device.DeviceInfo.TemperatureStatus.TemperatureSensor.i*/
#define RDM_OID_NETWORK_PROP                     74064	/*Device.DeviceInfo.NetworkProperties.i*/
#define RDM_OID_DEV_INFO_PROCESSOR               74148	/*Device.DeviceInfo.Processor.i*/
#define RDM_OID_DEV_INFO_VENDOR_LOG_FILE         74232	/*Device.DeviceInfo.VendorLogFile.i*/
#define RDM_OID_DEV_INFO_PROXIER_INFO            74364	/*Device.DeviceInfo.ProxierInfo.i*/
#define RDM_OID_DEV_INFO_LOC                     74496	/*Device.DeviceInfo.Location.i*/
#define RDM_OID_DEV_INFO_POWER_STAT              74652	/*Device.DeviceInfo.X_ZYXEL_PowerStatus*/
#define RDM_OID_VC_AUTO_HUNT                     74736	/*Device.X_ZYXEL_VcAutoHunt*/
#define RDM_OID_VC_HUNT_INFO                     74892	/*Device.X_ZYXEL_VcAutoHunt.VcHuntInfo.i*/
#define RDM_OID_VC_HUNT_RULE                     74976	/*Device.X_ZYXEL_VcAutoHunt.VcHuntInfo.i.VcHuntRule.i*/
#define RDM_OID_QOS                              75060	/*Device.QoS*/
#define RDM_OID_QOS_CLS                          75720	/*Device.QoS.Classification.i*/
#define RDM_OID_QOS_APP                          77844	/*Device.QoS.App.i*/
#define RDM_OID_QOS_FLOW                         78120	/*Device.QoS.Flow.i*/
#define RDM_OID_QOS_POLICER                      78444	/*Device.QoS.Policer.i*/
#define RDM_OID_QOS_QUE                          79008	/*Device.QoS.Queue.i*/
#define RDM_OID_QOS_QUE_STAT                     79548	/*Device.QoS.QueueStats.i*/
#define RDM_OID_QOS_SHAPER                       79848	/*Device.QoS.Shaper.i*/
#define RDM_OID_ZY_ONE_CONNECT                   80028	/*Device.X_ZYXEL_OneConnect*/
#define RDM_OID_ONE_CONNECT_INTERNET_ACCESS_MASTER_SWITCH 80232	/*Device.X_ZYXEL_OneConnect_Internet_Access_Filter*/
#define RDM_OID_ONE_CONNECT_INTERNET_ACCESS_RULE 80316	/*Device.X_ZYXEL_OneConnect_Internet_Access_Filter.Rule.i*/
#define RDM_OID_WIFI                             80448	/*Device.WiFi*/
#define RDM_OID_WIFI_ONE_SSID                    80700	/*Device.WiFi.X_ZYXEL_OneSSID*/
#define RDM_OID_WIFI_RADIO                       80760	/*Device.WiFi.Radio.i*/
#define RDM_OID_WIFI_RADIO_ST                    82596	/*Device.WiFi.Radio.i.Stats*/
#define RDM_OID_WIFI_SSID                        82848	/*Device.WiFi.SSID.i*/
#define RDM_OID_WIFI_SSID_STAT                   83604	/*Device.WiFi.SSID.i.Stats*/
#define RDM_OID_WIFI_ACCESS_POINT                84024	/*Device.WiFi.AccessPoint.i*/
#define RDM_OID_WIFI_ACCESS_POINT_SEC            84396	/*Device.WiFi.AccessPoint.i.Security*/
#define RDM_OID_WIFI_ACCESS_POINT_ACCOUNTING     85512	/*Device.WiFi.AccessPoint.i.Accounting*/
#define RDM_OID_WIFI_ACCESS_POINT_WPS            85740	/*Device.WiFi.AccessPoint.i.WPS*/
#define RDM_OID_WIFI_ACCESS_POINT_ASSOC_DEV      86232	/*Device.WiFi.AccessPoint.i.AssociatedDevice.i*/
#define RDM_OID_WIFI_ACCESS_POINT_ASSOC_DEV_ST   86532	/*Device.WiFi.AccessPoint.i.AssociatedDevice.i.Stats*/
#define RDM_OID_WIFI_STA_FILTER                  86784	/*Device.WiFi.AccessPoint.i.StationFilter*/
#define RDM_OID_WIFI_DIAGNOSTIC                  86892	/*Device.WiFi.NeighboringWiFiDiagnostic*/
#define RDM_OID_WIFI_DIAGNOSTIC_RESULTS          87000	/*Device.WiFi.NeighboringWiFiDiagnostic.Result.i*/
#define RDM_OID_WIFI_MAP                         87516	/*Device.WiFi.MultiAP*/
#define RDM_OID_WIFI_MAP_STEERING_SUM_ST         87576	/*Device.WiFi.MultiAP.SteeringSummaryStats*/
#define RDM_OID_WIFI_MAP_APDEV                   87804	/*Device.WiFi.MultiAP.APDevice.i*/
#define RDM_OID_WIFI_MAP_APDEV_RADIO             88200	/*Device.WiFi.MultiAP.APDevice.i.Radio.i*/
#define RDM_OID_WIFI_MAP_APDEV_RADIO_AP          88452	/*Device.WiFi.MultiAP.APDevice.i.Radio.i.AP.i*/
#define RDM_OID_WIFI_MAP_APDEV_RADIO_AP_ASSOCDEV 88632	/*Device.WiFi.MultiAP.APDevice.i.Radio.i.AP.i.AssociatedDevice.i*/
#define RDM_OID_WIFI_MAP_APDEV_RADIO_AP_ASSOCDEV_ST 88884	/*Device.WiFi.MultiAP.APDevice.i.Radio.i.AP.i.AssociatedDevice.i.Stats*/
#define RDM_OID_WIFI_MAP_APDEV_RADIO_AP_ASSOCDEV_STEERING_SUM_ST 89088	/*Device.WiFi.MultiAP.APDevice.i.Radio.i.AP.i.AssociatedDevice.i.SteeringSummaryStats*/
#define RDM_OID_WIFI_MAP_APDEV_RADIO_AP_ASSOCDEV_STEERING_HISTORY 89340	/*Device.WiFi.MultiAP.APDevice.i.Radio.i.AP.i.AssociatedDevice.i.SteeringHistory.i*/
#define RDM_OID_ZY_SFP_MANAGEMENT                89520	/*Device.X_ZYXEL_SFP_Management*/
#define RDM_OID_USB                              89628	/*Device.USB*/
#define RDM_OID_USB_INTF                         89712	/*Device.USB.Interface.i*/
#define RDM_OID_USB_INTF_STAT                    90012	/*Device.USB.Interface.i.Stats*/
#define RDM_OID_USB_PORT                         90408	/*Device.USB.Port.i*/
#define RDM_OID_USB_USBHOSTS                     90636	/*Device.USB.USBHosts*/
#define RDM_OID_USB_USBHOSTS_HOST                90696	/*Device.USB.USBHosts.Host.i*/
#define RDM_OID_USB_USBHOSTS_HOST_DEV            90924	/*Device.USB.USBHosts.Host.i.Device.i*/
#define RDM_OID_USB_USBHOSTS_HOST_DEV_PAR        91440	/*Device.USB.USBHosts.Host.i.Device.i.X_ZYXEL_Partition.i*/
#define RDM_OID_USB_USBHOSTS_HOST_DEV_CFG        91596	/*Device.USB.USBHosts.Host.i.Device.i.Configuration.i*/
#define RDM_OID_USB_USBHOSTS_HOST_DEV_CFG_INTF   91680	/*Device.USB.USBHosts.Host.i.Device.i.Configuration.i.Interface.i*/
#define RDM_OID_S_T_B_VENDOR_I_D                 91812	/*Device.X_ZYXEL_STB_VENDOR_ID*/
#define RDM_OID_HOME_CYBER_SECURITY              91968	/*Device.X_ZYXEL_HomeCyberSecurity*/
#define RDM_OID_ATM                              92124	/*Device.ATM*/
#define RDM_OID_ATM_LINK                         92184	/*Device.ATM.Link.i*/
#define RDM_OID_ATM_LINK_ST                      92772	/*Device.ATM.Link.i.Stats*/
#define RDM_OID_ATM_LINK_QOS                     93384	/*Device.ATM.Link.i.QoS*/
#define RDM_OID_ATM_DIAG                         93540	/*Device.ATM.Diagnostics*/
#define RDM_OID_ATM_DIAG_F5_LO                   93576	/*Device.ATM.Diagnostics.F5Loopback*/
#define RDM_OID_ATM_DIAG_F4_LO                   93876	/*Device.ATM.Diagnostics.X_ZYXEL_F4Loopback*/
#define RDM_OID_DSL                              94176	/*Device.DSL*/
#define RDM_OID_DSL_LINE                         94308	/*Device.DSL.Line.i*/
#define RDM_OID_DSL_LINE_ST                      98520	/*Device.DSL.Line.i.Stats*/
#define RDM_OID_DSL_LINE_ST_TOTAL                98892	/*Device.DSL.Line.i.Stats.Total*/
#define RDM_OID_DSL_LINE_ST_SHOWTIME             99624	/*Device.DSL.Line.i.Stats.Showtime*/
#define RDM_OID_DSL_LINE_ST_LAST_SHOWTIME        100164	/*Device.DSL.Line.i.Stats.LastShowtime*/
#define RDM_OID_DSL_LINE_ST_LAST_CUR_DAY         100248	/*Device.DSL.Line.i.Stats.CurrentDay*/
#define RDM_OID_DSL_LINE_ST_LAST_QUAR_HR         100740	/*Device.DSL.Line.i.Stats.QuarterHour*/
#define RDM_OID_DSL_LINE_TEST_PARAMS             101232	/*Device.DSL.Line.i.TestParams*/
#define RDM_OID_DSL_CHANNEL                      101796	/*Device.DSL.Channel.i*/
#define RDM_OID_DSL_CHANNEL_ST                   102336	/*Device.DSL.Channel.i.Stats*/
#define RDM_OID_DSL_CHANNEL_ST_TOTAL             102708	/*Device.DSL.Channel.i.Stats.Total*/
#define RDM_OID_DSL_CHANNEL_ST_SHOWTIME          102888	/*Device.DSL.Channel.i.Stats.Showtime*/
#define RDM_OID_DSL_CHANNEL_ST_LAST_SHOWTIME     103068	/*Device.DSL.Channel.i.Stats.LastShowtime*/
#define RDM_OID_DSL_CHANNEL_ST_CUR_DAY           103248	/*Device.DSL.Channel.i.Stats.CurrentDay*/
#define RDM_OID_DSL_CHANNEL_ST_QUAR_HR           103428	/*Device.DSL.Channel.i.Stats.QuarterHour*/
#define RDM_OID_DSL_BOND_GP                      103608	/*Device.DSL.BondingGroup.i*/
#define RDM_OID_DSL_BOND_GP_BONDED_CHANNEL       104124	/*Device.DSL.BondingGroup.i.BondedChannel.i*/
#define RDM_OID_DSL_BOND_GP_BONDED_CHANNEL_ETH   104208	/*Device.DSL.BondingGroup.i.BondedChannel.i.Ethernet*/
#define RDM_OID_DSL_BOND_GP_BONDED_CHANNEL_ETH_ST 104244	/*Device.DSL.BondingGroup.i.BondedChannel.i.Ethernet.Stats*/
#define RDM_OID_DSL_BOND_GP_ST                   104472	/*Device.DSL.BondingGroup.i.Stats*/
#define RDM_OID_DSL_BOND_GP_ST_TOTAL             104940	/*Device.DSL.BondingGroup.i.Stats.Total*/
#define RDM_OID_DSL_BOND_GP_ST_CURRENT_DAY       105240	/*Device.DSL.BondingGroup.i.Stats.CurrentDay*/
#define RDM_OID_DSL_BOND_GP_ST_QTR_HR            105540	/*Device.DSL.BondingGroup.i.Stats.QuarterHour*/
#define RDM_OID_DSL_BOND_GP_ETH                  105840	/*Device.DSL.BondingGroup.i.Ethernet*/
#define RDM_OID_DSL_BOND_GP_ETH_ST               105876	/*Device.DSL.BondingGroup.i.Ethernet.Stats*/
#define RDM_OID_DSL_DIAG                         106296	/*Device.DSL.Diagnostics*/
#define RDM_OID_DSL_DIAG_ADSL_LINE_TEST          106332	/*Device.DSL.Diagnostics.ADSLLineTest*/
#define RDM_OID_SCHEDULE                         107232	/*Device.X_ZYXEL_Schedule.i*/
#define RDM_OID_LIFEMOTE_AGENT                   107532	/*Device.X_ZYXEL_LifeMoteAgent*/
#define RDM_OID_SW_MODULE                        107640	/*Device.SoftwareModules*/
#define RDM_OID_SW_MODULE_EE_CONF                107748	/*Device.SoftwareModules.X_ZYXEL_ExecEnvConfigure*/
#define RDM_OID_SW_MODULE_EXEC_ENV               107880	/*Device.SoftwareModules.ExecEnv.i*/
#define RDM_OID_SW_MODULE_DEPLOYMENT_UNIT        108396	/*Device.SoftwareModules.DeploymentUnit.i*/
#define RDM_OID_SW_MODULE_EXEC_UNIT              108768	/*Device.SoftwareModules.ExecutionUnit.i*/
#define RDM_OID_SW_MODULE_EXEC_UNIT_EXTENSIONS   109308	/*Device.SoftwareModules.ExecutionUnit.i.Extensions*/
#define RDM_OID_T_F_T_P_SRV_NAME                 109392	/*Device.X_ZYXEL_TFTP_SERVER_NAME*/
#define RDM_OID_U_R_L_FILTER                     109452	/*Device.X_ZYXEL_URLFilter.i*/
#define RDM_OID_WHITE_U_R_L_FILTER               109584	/*Device.X_ZYXEL_URLFilter.i.WhiteList.i*/
#define RDM_OID_BLACK_U_R_L_FILTER               109692	/*Device.X_ZYXEL_URLFilter.i.BlackList.i*/
#define RDM_OID_ZY_SNMP                          109800	/*Device.X_ZYXEL_SNMP*/
#define RDM_OID_TRAP_ADDR                        109956	/*Device.X_ZYXEL_SNMP.TrapAddr.i*/
#define RDM_OID_GRE                              110064	/*Device.GRE*/
#define RDM_OID_GRE_TUNNEL                       110148	/*Device.GRE.Tunnel.i*/
#define RDM_OID_GRE_TUNNEL_STAT                  110688	/*Device.GRE.Tunnel.i.Stats*/
#define RDM_OID_GRE_TUNNEL_IFACE                 110964	/*Device.GRE.Tunnel.i.Interface.i*/
#define RDM_OID_GRE_TUNNEL_IFACE_STAT            111264	/*Device.GRE.Tunnel.i.Interface.i.Stats*/
#define RDM_OID_GRE_FILTER                       111492	/*Device.GRE.Filter.i*/
#define RDM_OID_ZY_W_W_A_N_BACKUP                111744	/*Device.X_ZYXEL_WWAN_BACKUP*/
#define RDM_OID_ZY_W_W_A_N_PING_CHECK            112212	/*Device.X_ZYXEL_WWAN_BACKUP.PingCheck*/
#define RDM_OID_ZY_W_W_A_N_BUDGET_CONTROL        112416	/*Device.X_ZYXEL_WWAN_BACKUP.BudgetControl*/
#define RDM_OID_ZY_W_W_A_N_STAT                  113100	/*Device.X_ZYXEL_WWAN_BACKUP.Stats*/
#define RDM_OID_DLNA                             113496	/*Device.DLNA*/
#define RDM_OID_DLNA_CAPB                        113676	/*Device.DLNA.Capabilities*/
#define RDM_OID_PTM                              113904	/*Device.PTM*/
#define RDM_OID_PTM_LINK                         113964	/*Device.PTM.Link.i*/
#define RDM_OID_PTM_LINK_ST                      114576	/*Device.PTM.Link.i.Stats*/
#define RDM_OID_UPNP                             115092	/*Device.UPnP*/
#define RDM_OID_UPNP_DEV                         115128	/*Device.UPnP.Device*/
#define RDM_OID_UPNP_DEV_CAPB                    115452	/*Device.UPnP.Device.Capabilities*/
#define RDM_OID_UPNP_DISC                        115776	/*Device.UPnP.Discovery*/
#define RDM_OID_UPNP_DISC_ROOT_DEV               115884	/*Device.UPnP.Discovery.RootDevice.i*/
#define RDM_OID_UPNP_DISC_DEV                    116088	/*Device.UPnP.Discovery.Device.i*/
#define RDM_OID_UPNP_DISC_SERVICE                116292	/*Device.UPnP.Discovery.Service.i*/
#define RDM_OID_GPON_INFO                        116472	/*Device.X_ZYXEL_GPON_Info*/

#define RDM_OID_MAX                   116700     // for OID validation

#define RDM_OID_IS_INVALID(_oid_)    ((_oid_ < 0) || (_oid_ >= RDM_OID_MAX))

#endif // _ZCFG_RDM_OID_H
