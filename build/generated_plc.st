PROGRAM Sludge
  VAR
    InletValveStatus AT %IX0.12 : BOOL;
    OverflowSensor AT %IX0.13 : BOOL;
    PumpStatus AT %IX0.14 : BOOL;
    DisinfectantStatus AT %IX0.17 : BOOL;
    GasHighVolumeAlert AT %IX0.25 : BOOL;
    InletControl AT %QX0.1 : BOOL;
    OutletControl AT %QX0.2 : BOOL;
    SludgeOutPump AT %QX0.5 : BOOL;
    ActivatePumpAdjust AT %QX0.6 : BOOL;
    OverflowValveOpen AT %QX0.13 : BOOL;
    SolidWasteAlarm AT %QX0.15 : BOOL;
    FiltrationControl AT %QX0.16 : BOOL;
    ThickeningPump AT %QX0.20 : BOOL;
    DigesterPump AT %QX0.22 : BOOL;
    HotWaterPumpIn AT %QX0.23 : BOOL;
    HotWaterPumpOut AT %QX0.24 : BOOL;
    GasPumpToTransport AT %QX0.25 : BOOL;
    pHValid AT %QX0.26 : BOOL;
    UVLowerStrength AT %QX0.27 : BOOL;
    UVIncreaseStrength AT %QX0.28 : BOOL;
    InflowSensor AT %MW0.1 : INT;
    DissolvedO2 AT %MW0.3 : INT;
    pHSensor AT %MW0.4 : INT;
    TurbiditySensor AT %MW0.5 : INT;
    TSSSensor AT %MW0.7 : INT;
    UVPower AT %MW1.71 : INT;
    O2Demand AT %MW0.8 : INT;
    Const5 AT %MW3.5 : INT := 5;
    SludgePumpVolume AT %MW3.51 : INT;
    Const10000 AT %MW3.6 : INT := 10000;
    phUpper AT %MW3.7 : INT := 8;
    pHLower AT %MW3.8 : INT := 6;
    TurbidityThreshold AT %MW3.52 : INT := 10000;
    TSSThreshold AT %MW3.71 : INT := 275;
    UVUpper AT %MW3.81 : INT := 10500;
    UVLower AT %MW3.9 : INT := 0;
  END_VAR
  VAR
    _TMP_GT8_OUT : BOOL;
    _TMP_GT21_OUT : BOOL;
    _TMP_GE27_OUT : BOOL;
    _TMP_GT33_OUT : BOOL;
    _TMP_GT15_OUT : BOOL;
    _TMP_LT46_OUT : BOOL;
    _TMP_LT38_OUT : BOOL;
    _TMP_AND44_OUT : BOOL;
    _TMP_LT40_OUT : BOOL;
    _TMP_GT56_OUT : BOOL;
    _TMP_AND57_OUT : BOOL;
    _TMP_LT50_OUT : BOOL;
    _TMP_GT65_OUT : BOOL;
    _TMP_AND52_OUT : BOOL;
    _TMP_LT62_OUT : BOOL;
    _TMP_GT72_OUT : BOOL;
    _TMP_SUB39_OUT : INT;
  END_VAR

  ThickeningPump := OverflowSensor;
  DigesterPump := OverflowSensor AND SolidWasteAlarm;
  _TMP_GT8_OUT := GT(DissolvedO2, O2Demand);
  HotWaterPumpOut := _TMP_GT8_OUT;
  _TMP_GT21_OUT := GT(O2Demand, DissolvedO2);
  HotWaterPumpIn := _TMP_GT21_OUT;
  GasPumpToTransport := GasHighVolumeAlert;
  _TMP_GE27_OUT := GE(SludgePumpVolume, Const5);
  SludgeOutPump := _TMP_GE27_OUT OR NOT(OverflowSensor) AND PumpStatus;
  _TMP_GT33_OUT := GT(Const10000, InflowSensor);
  InletControl := _TMP_GT33_OUT;
  InletValveStatus := InletControl;
  _TMP_GT15_OUT := GT(InflowSensor, Const10000);
  ActivatePumpAdjust := _TMP_GT15_OUT;
  OverflowValveOpen := OverflowSensor;
  _TMP_LT46_OUT := LT(TurbiditySensor, TurbidityThreshold);
  _TMP_LT38_OUT := LT(TSSSensor, TSSThreshold);
  _TMP_AND44_OUT := AND(_TMP_LT46_OUT, _TMP_LT38_OUT);
  FiltrationControl := pHValid AND _TMP_AND44_OUT;
  _TMP_LT40_OUT := LT(phUpper, pHSensor);
  _TMP_GT56_OUT := GT(pHSensor, pHLower);
  _TMP_AND57_OUT := AND(_TMP_LT40_OUT, _TMP_GT56_OUT);
  pHValid := _TMP_AND57_OUT;
  PumpStatus := pHValid AND _TMP_AND44_OUT;
  _TMP_LT50_OUT := LT(UVUpper, UVPower);
  _TMP_GT65_OUT := GT(UVPower, UVLower);
  _TMP_AND52_OUT := AND(_TMP_LT50_OUT, _TMP_GT65_OUT);
  OutletControl := DisinfectantStatus AND _TMP_AND52_OUT;
  _TMP_LT62_OUT := LT(UVLower, UVPower);
  UVIncreaseStrength := _TMP_LT62_OUT;
  _TMP_GT72_OUT := GT(UVPower, UVUpper);
  UVLowerStrength := _TMP_GT72_OUT;
  DisinfectantStatus := _TMP_LT62_OUT;
  _TMP_SUB39_OUT := SUB(InflowSensor, Const10000);
END_PROGRAM

PROGRAM influent
  VAR
    InfluentWaterFlow AT %IX0.1 : INT;
    EffluentWaterFlow AT %IX0.2 : INT;
    AirFlow AT %IX0.3 : INT;
    PretreatmentUnitFlow AT %IX0.4 : INT;
    ClarifierWaterDepth AT %IX0.5 : INT := 4;
    ClarifierWaterTemp AT %IX0.6 : INT;
    AerobicSurface AT %IX0.7 : INT;
    AerobicReactorAirflow AT %IX0.8 : LINT;
    AerobicWaterLevel AT %IX0.9 : INT;
    TSS AT %IX0.11 : INT;
    SandContainerFlow AT %IX0.18 : INT;
    SandWaterLevelHigh AT %IX0.19 : BOOL := 0;
    AirBlower AT %QX0.3 : BOOL;
    FerrousChemicalDeploy AT %QX0.4 : BOOL;
    PretreatInletControlStatus AT %QX1.1 : BOOL;
    PretreatOutletControlStatus AT %QX1.2 : BOOL;
    ScreeningContainerEffluentValve AT %QX1.3 : BOOL;
    SandContainerEffluentValve AT %QX1.4 : BOOL;
    ScreeningContSludgeEffluentValve AT %QX1.5 : BOOL;
    ClarifierOutletValve AT %QX1.6 : BOOL;
    AirMinFlow AT %MW1.1 : LINT := 49923;
    AirMaxFlow AT %MW1.2 : LINT := 186302;
    TempMin AT %MW1.3 : INT := 17;
    TempMax AT %MW1.4 : INT := 30;
    DesignFlow AT %MW1.5 : INT := 10000;
    DryWeatherFlow AT %MW1.6 : INT := 27702;
    TSSThreshold AT %MW1.7 : INT := 275;
    BOD5Threshold AT %MW1.8 : INT := 313;
    InfluentFlowValveStatus AT %MW1.9 : BOOL := 0;
    ClarifierWaterDepthThreshold AT %MW1.10 : INT := 4;
    ClarifierSurface AT %MW1.11 : INT := 144;
  END_VAR
  VAR
    _TMP_LE7_OUT : BOOL;
    _TMP_GT15_OUT : BOOL;
    _TMP_LT17_OUT : BOOL;
    _TMP_GT21_OUT : BOOL;
    _TMP_GT27_OUT : BOOL;
  END_VAR

  _TMP_LE7_OUT := LE(InfluentWaterFlow, DryWeatherFlow);
  PretreatInletControlStatus := _TMP_LE7_OUT;
  SandContainerEffluentValve := SandWaterLevelHigh;
  ScreeningContainerEffluentValve := SandWaterLevelHigh;
  _TMP_GT15_OUT := GT(ClarifierWaterDepth, ClarifierWaterDepthThreshold);
  ClarifierOutletValve := _TMP_GT15_OUT;
  _TMP_LT17_OUT := LT(AerobicReactorAirflow, AirMinFlow);
  AirBlower := _TMP_LT17_OUT;
  _TMP_GT21_OUT := GT(AerobicReactorAirflow, AirMaxFlow);
  AirBlower := NOT(_TMP_GT21_OUT);
  _TMP_GT27_OUT := GT(TSS, TSSThreshold);
  FerrousChemicalDeploy := _TMP_GT27_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : Sludge;
  END_RESOURCE
END_CONFIGURATION
