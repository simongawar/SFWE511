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
    InletValveStatus : BOOL;
    OverflowSensor : BOOL;
    PumpStatus : BOOL;
    DisinfectantStatus : BOOL;
    GasHighVolumeAlert : BOOL;
    InletControl : BOOL;
    OutletControl : BOOL;
    SludgeOutPump : BOOL;
    ActivatePumpAdjust : BOOL;
    OverflowValveOpen : BOOL;
    SolidWasteAlarm : BOOL;
    FiltrationControl : BOOL;
    ThickeningPump : BOOL;
    DigesterPump : BOOL;
    HotWaterPumpIn : BOOL;
    HotWaterPumpOut : BOOL;
    GasPumpToTransport : BOOL;
    pHValid : BOOL;
    UVLowerStrength : BOOL;
    UVIncreaseStrength : BOOL;
    InflowSensor : INT;
    DissolvedO2 : INT;
    pHSensor : INT;
    TurbiditySensor : INT;
    TSSSensor : INT;
    UVPower : INT;
    O2Demand : INT;
    Const5 : INT := 5;
    SludgePumpVolume : INT;
    Const10000 : INT := 10000;
    phUpper : INT := 8;
    pHLower : INT := 6;
    TurbidityThreshold : INT := 10000;
    TSSThreshold : INT := 275;
    UVUpper : INT := 10500;
    UVLower : INT := 0;
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
    InfluentWaterFlow : INT;
    EffluentWaterFlow : INT;
    AirFlow : INT;
    PretreatmentUnitFlow : INT;
    ClarifierWaterDepth : INT := 4;
    ClarifierWaterTemp : INT;
    AerobicSurface : INT;
    AerobicReactorAirflow : LINT;
    AerobicWaterLevel : INT;
    TSS : INT;
    SandContainerFlow : INT;
    SandWaterLevelHigh : BOOL := 0;
    AirBlower : BOOL;
    FerrousChemicalDeploy : BOOL;
    PretreatInletControlStatus : BOOL;
    PretreatOutletControlStatus : BOOL;
    ScreeningContainerEffluentValve : BOOL;
    SandContainerEffluentValve : BOOL;
    ScreeningContSludgeEffluentValve : BOOL;
    ClarifierOutletValve : BOOL;
    AirMinFlow : LINT := 49923;
    AirMaxFlow : LINT := 186302;
    TempMin : INT := 17;
    TempMax : INT := 30;
    DesignFlow : INT := 10000;
    DryWeatherFlow : INT := 27702;
    TSSThreshold : INT := 275;
    BOD5Threshold : INT := 313;
    InfluentFlowValveStatus : BOOL := 0;
    ClarifierWaterDepthThreshold : INT := 4;
    ClarifierSurface : INT := 144;
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
