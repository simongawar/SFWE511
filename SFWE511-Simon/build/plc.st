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


PROGRAM Humus
  VAR
    FilterPresureSwitchHigh : INT;
    FilterPressureSwitchLow : INT;
    RoughingTricklingFilterVolume : INT := 1063 M^3;
    RoughingCircularHumusTank : INT := 144.3 M^2;
    SludgePumpControl : BOOL;
    MixerControl : BOOL;
    FilterFlowControlvalve : BOOL;
    FilterationControl : BOOL;
  END_VAR
  VAR
    _TMP_GT3_OUT : BOOL;
    _TMP_LT7_OUT : BOOL;
    _TMP_GE14_OUT : BOOL;
    _TMP_GE21_OUT : BOOL;
  END_VAR

  _TMP_GT3_OUT := GT(FilterPresureSwitchHigh, 144.3);
  FilterationControl := _TMP_GT3_OUT;
  _TMP_LT7_OUT := LT(FilterPressureSwitchLow, 144.3);
  FilterationControl := _TMP_LT7_OUT;
  _TMP_GE14_OUT := GE(RoughingTricklingFilterVolume, 1063);
  FilterFlowControlvalve := _TMP_GE14_OUT;
  FilterFlowControlvalve := MixerControl;
  _TMP_GE21_OUT := GE(RoughingCircularHumusTank, 144.3);
  SludgePumpControl := _TMP_GE21_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : Humus;
  END_RESOURCE
END_CONFIGURATION
