<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="spartan6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="XLXN_8" />
        <signal name="XLXN_13" />
        <signal name="c" />
        <signal name="XLXN_15" />
        <signal name="XLXN_17" />
        <signal name="b" />
        <signal name="XLXN_21" />
        <signal name="a" />
        <signal name="XLXN_23" />
        <signal name="XLXN_24" />
        <signal name="XLXN_25" />
        <signal name="XLXN_26" />
        <signal name="XLXN_27" />
        <signal name="XLXN_28" />
        <signal name="XLXN_30" />
        <signal name="XLXN_31" />
        <signal name="XLXN_32" />
        <port polarity="Input" name="c" />
        <port polarity="Input" name="b" />
        <port polarity="Input" name="a" />
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="or3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="72" y1="-128" y2="-128" x1="0" />
            <line x2="48" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <arc ex="192" ey="-128" sx="112" sy="-80" r="88" cx="116" cy="-168" />
            <arc ex="48" ey="-176" sx="48" sy="-80" r="56" cx="16" cy="-128" />
            <line x2="48" y1="-64" y2="-80" x1="48" />
            <line x2="48" y1="-192" y2="-176" x1="48" />
            <line x2="48" y1="-80" y2="-80" x1="112" />
            <arc ex="112" ey="-176" sx="192" sy="-128" r="88" cx="116" cy="-88" />
            <line x2="48" y1="-176" y2="-176" x1="112" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="and3">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="192" y1="-128" y2="-128" x1="256" />
            <line x2="144" y1="-176" y2="-176" x1="64" />
            <line x2="64" y1="-80" y2="-80" x1="144" />
            <arc ex="144" ey="-176" sx="144" sy="-80" r="48" cx="144" cy="-128" />
            <line x2="64" y1="-64" y2="-192" x1="64" />
        </blockdef>
        <blockdef name="nor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="or2" name="XLXI_1">
            <blockpin signalname="b" name="I0" />
            <blockpin signalname="a" name="I1" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_2">
            <blockpin signalname="XLXN_4" name="I0" />
            <blockpin signalname="XLXN_2" name="I1" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="or3" name="XLXI_3">
            <blockpin signalname="c" name="I0" />
            <blockpin signalname="b" name="I1" />
            <blockpin signalname="a" name="I2" />
            <blockpin signalname="XLXN_8" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="c" name="I0" />
            <blockpin signalname="XLXN_1" name="I1" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="b" name="I0" />
            <blockpin signalname="a" name="I1" />
            <blockpin signalname="XLXN_4" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_6">
            <blockpin signalname="XLXN_8" name="I0" />
            <blockpin signalname="XLXN_6" name="I1" />
            <blockpin signalname="XLXN_7" name="O" />
        </block>
        <block symbolname="and3" name="XLXI_7">
            <blockpin signalname="c" name="I0" />
            <blockpin signalname="b" name="I1" />
            <blockpin signalname="a" name="I2" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="nor2" name="XLXI_8">
            <blockpin signalname="XLXN_13" name="I0" />
            <blockpin signalname="XLXN_7" name="I1" />
            <blockpin name="O" />
        </block>
        <block symbolname="inv" name="XLXI_9">
            <blockpin signalname="XLXN_6" name="I" />
            <blockpin name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="2160" y="1408" name="XLXI_8" orien="R0" />
        <instance x="2144" y="800" name="XLXI_2" orien="R0" />
        <instance x="2720" y="736" name="XLXI_9" orien="R0" />
        <instance x="1664" y="992" name="XLXI_5" orien="R0" />
        <branch name="XLXN_2">
            <wire x2="2128" y1="704" y2="704" x1="1872" />
            <wire x2="2144" y1="672" y2="672" x1="2128" />
            <wire x2="2128" y1="672" y2="704" x1="2128" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="2032" y1="896" y2="896" x1="1920" />
            <wire x2="2032" y1="736" y2="896" x1="2032" />
            <wire x2="2144" y1="736" y2="736" x1="2032" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="2144" y1="1184" y2="1184" x1="1920" />
            <wire x2="2144" y1="1184" y2="1280" x1="2144" />
            <wire x2="2160" y1="1280" y2="1280" x1="2144" />
        </branch>
        <instance x="1664" y="1536" name="XLXI_7" orien="R0" />
        <instance x="1664" y="1280" name="XLXI_6" orien="R0" />
        <branch name="XLXN_6">
            <wire x2="1600" y1="1072" y2="1152" x1="1600" />
            <wire x2="1664" y1="1152" y2="1152" x1="1600" />
            <wire x2="2544" y1="1072" y2="1072" x1="1600" />
            <wire x2="2544" y1="704" y2="704" x1="2400" />
            <wire x2="2720" y1="704" y2="704" x1="2544" />
            <wire x2="2544" y1="704" y2="1072" x1="2544" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="1664" y1="1216" y2="1216" x1="1424" />
        </branch>
        <branch name="XLXN_13">
            <wire x2="2032" y1="1408" y2="1408" x1="1920" />
            <wire x2="2032" y1="1344" y2="1408" x1="2032" />
            <wire x2="2160" y1="1344" y2="1344" x1="2032" />
        </branch>
        <iomarker fontsize="28" x="960" y="1472" name="c" orien="R180" />
        <branch name="c">
            <wire x2="1088" y1="1472" y2="1472" x1="960" />
            <wire x2="1664" y1="1472" y2="1472" x1="1088" />
            <wire x2="1088" y1="752" y2="1280" x1="1088" />
            <wire x2="1168" y1="1280" y2="1280" x1="1088" />
            <wire x2="1088" y1="1280" y2="1472" x1="1088" />
            <wire x2="1616" y1="752" y2="752" x1="1088" />
            <wire x2="1616" y1="736" y2="752" x1="1616" />
        </branch>
        <branch name="b">
            <wire x2="1024" y1="1408" y2="1408" x1="960" />
            <wire x2="1664" y1="1408" y2="1408" x1="1024" />
            <wire x2="1184" y1="656" y2="656" x1="1024" />
            <wire x2="1024" y1="656" y2="928" x1="1024" />
            <wire x2="1024" y1="928" y2="1216" x1="1024" />
            <wire x2="1168" y1="1216" y2="1216" x1="1024" />
            <wire x2="1024" y1="1216" y2="1408" x1="1024" />
            <wire x2="1664" y1="928" y2="928" x1="1024" />
        </branch>
        <instance x="1168" y="1344" name="XLXI_3" orien="R0" />
        <branch name="a">
            <wire x2="976" y1="1344" y2="1344" x1="960" />
            <wire x2="1664" y1="1344" y2="1344" x1="976" />
            <wire x2="1184" y1="592" y2="592" x1="976" />
            <wire x2="976" y1="592" y2="864" x1="976" />
            <wire x2="976" y1="864" y2="1152" x1="976" />
            <wire x2="1168" y1="1152" y2="1152" x1="976" />
            <wire x2="976" y1="1152" y2="1344" x1="976" />
            <wire x2="1664" y1="864" y2="864" x1="976" />
        </branch>
        <iomarker fontsize="28" x="960" y="1344" name="a" orien="R180" />
        <iomarker fontsize="28" x="960" y="1408" name="b" orien="R180" />
        <branch name="XLXN_1">
            <wire x2="1600" y1="624" y2="624" x1="1440" />
            <wire x2="1600" y1="624" y2="672" x1="1600" />
            <wire x2="1616" y1="672" y2="672" x1="1600" />
        </branch>
        <instance x="1616" y="800" name="XLXI_4" orien="R0" />
        <instance x="1184" y="720" name="XLXI_1" orien="R0" />
    </sheet>
</drawing>