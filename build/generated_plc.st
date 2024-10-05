PROGRAM Sludge
  VAR
    OverflowSensor AT %IX0.13 : BOOL;
    PumpStatus AT %IX0.14 : BOOL;
    GasHighVolumeAlert AT %IX0.25 : BOOL;
    SludgeOutPump AT %QX0.5 : BOOL;
    ThickeningPump AT %QX0.20 : BOOL;
    SolidWasteAlarm AT %QX0.15 : BOOL;
    ThickeningPump0 AT %QX0.21 : BOOL;
    DigesterPump AT %QX0.22 : BOOL;
    HotWaterPumpIn AT %QX0.23 : BOOL;
    HotWaterPumpOut AT %QX0.24 : BOOL;
    GasPumpToTransport AT %QX0.25 : BOOL;
    DissolvedO2 AT %MW0.3 : INT;
    O2Demand AT %MW0.8 : INT;
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
