TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM Sludge
  VAR
    OverflowSensor : BOOL;
    PumpStatus : BOOL;
    GasHighVolumeAlert : BOOL;
    SludgeOutPump : BOOL;
    ThickeningPump : BOOL;
    SolidWasteAlarm : BOOL;
    ThickeningPump0 : BOOL;
    DigesterPump : BOOL;
    HotWaterPumpIn : BOOL;
    HotWaterPumpOut : BOOL;
    GasPumpToTransport : BOOL;
    DissolvedO2 : INT;
    O2Demand : INT;
  END_VAR
  VAR
    _TMP_GT8_OUT : BOOL;
    _TMP_GT21_OUT : BOOL;
  END_VAR

  SludgeOutPump := PumpStatus;
  ThickeningPump := OverflowSensor;
  DigesterPump := OverflowSensor AND SolidWasteAlarm;
  _TMP_GT8_OUT := GT(DissolvedO2, O2Demand);
  HotWaterPumpOut := _TMP_GT8_OUT;
  _TMP_GT21_OUT := GT(O2Demand, DissolvedO2);
  HotWaterPumpIn := _TMP_GT21_OUT;
  GasPumpToTransport := GasHighVolumeAlert;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : Sludge;
  END_RESOURCE
END_CONFIGURATION
