PROGRAM Humus
  VAR
    FilterPresureSwitchHigh AT %IX0.15 : INT;
    FilterPressureSwitchLow AT %IX0.16 : INT;
    RoughingTricklingFilterVolume AT %MW0.0 : INT := 1063 M^3;
    RoughingCircularHumusTank AT %MW0.1 : INT := 144.3 M^2;
    SludgePumpControl AT %QX0.5 : BOOL;
    MixerControl AT %QX0.6 : BOOL;
    FilterFlowControlvalve AT %QX0.8 : BOOL;
    FilterationControl AT %QX0.16 : BOOL;
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
