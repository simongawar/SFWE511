void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void SLUDGE_init__(SLUDGE *data__, BOOL retain) {
  __INIT_VAR(data__->INLETVALVESTATUS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OVERFLOWSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUMPSTATUS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DISINFECTANTSTATUS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GASHIGHVOLUMEALERT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INLETCONTROL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUTLETCONTROL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SLUDGEOUTPUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ACTIVATEPUMPADJUST,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OVERFLOWVALVEOPEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SOLIDWASTEALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILTRATIONCONTROL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->THICKENINGPUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DIGESTERPUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HOTWATERPUMPIN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HOTWATERPUMPOUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GASPUMPTOTRANSPORT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PHVALID,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UVLOWERSTRENGTH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UVINCREASESTRENGTH,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->INFLOWSENSOR,0,retain)
  __INIT_VAR(data__->DISSOLVEDO2,0,retain)
  __INIT_VAR(data__->PHSENSOR,0,retain)
  __INIT_VAR(data__->TURBIDITYSENSOR,0,retain)
  __INIT_VAR(data__->TSSSENSOR,0,retain)
  __INIT_VAR(data__->UVPOWER,0,retain)
  __INIT_VAR(data__->O2DEMAND,0,retain)
  __INIT_VAR(data__->CONST5,5,retain)
  __INIT_VAR(data__->SLUDGEPUMPVOLUME,0,retain)
  __INIT_VAR(data__->CONST10000,10000,retain)
  __INIT_VAR(data__->PHUPPER,8,retain)
  __INIT_VAR(data__->PHLOWER,6,retain)
  __INIT_VAR(data__->TURBIDITYTHRESHOLD,10000,retain)
  __INIT_VAR(data__->TSSTHRESHOLD,275,retain)
  __INIT_VAR(data__->UVUPPER,10500,retain)
  __INIT_VAR(data__->UVLOWER,0,retain)
  __INIT_VAR(data__->_TMP_GT8_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT21_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE27_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT33_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT15_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT46_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT38_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND44_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT40_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT56_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND57_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT50_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT65_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND52_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT62_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT72_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SUB39_OUT,0,retain)
}

// Code part
void SLUDGE_body__(SLUDGE *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,THICKENINGPUMP,,__GET_VAR(data__->OVERFLOWSENSOR,));
  __SET_VAR(data__->,DIGESTERPUMP,,(__GET_VAR(data__->OVERFLOWSENSOR,) && __GET_VAR(data__->SOLIDWASTEALARM,)));
  __SET_VAR(data__->,_TMP_GT8_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->DISSOLVEDO2,),
    (INT)__GET_VAR(data__->O2DEMAND,)));
  __SET_VAR(data__->,HOTWATERPUMPOUT,,__GET_VAR(data__->_TMP_GT8_OUT,));
  __SET_VAR(data__->,_TMP_GT21_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->O2DEMAND,),
    (INT)__GET_VAR(data__->DISSOLVEDO2,)));
  __SET_VAR(data__->,HOTWATERPUMPIN,,__GET_VAR(data__->_TMP_GT21_OUT,));
  __SET_VAR(data__->,GASPUMPTOTRANSPORT,,__GET_VAR(data__->GASHIGHVOLUMEALERT,));
  __SET_VAR(data__->,_TMP_GE27_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->SLUDGEPUMPVOLUME,),
    (INT)__GET_VAR(data__->CONST5,)));
  __SET_VAR(data__->,SLUDGEOUTPUMP,,(__GET_VAR(data__->_TMP_GE27_OUT,) || (!(__GET_VAR(data__->OVERFLOWSENSOR,)) && __GET_VAR(data__->PUMPSTATUS,))));
  __SET_VAR(data__->,_TMP_GT33_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CONST10000,),
    (INT)__GET_VAR(data__->INFLOWSENSOR,)));
  __SET_VAR(data__->,INLETCONTROL,,__GET_VAR(data__->_TMP_GT33_OUT,));
  __SET_VAR(data__->,INLETVALVESTATUS,,__GET_VAR(data__->INLETCONTROL,));
  __SET_VAR(data__->,_TMP_GT15_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->INFLOWSENSOR,),
    (INT)__GET_VAR(data__->CONST10000,)));
  __SET_VAR(data__->,ACTIVATEPUMPADJUST,,__GET_VAR(data__->_TMP_GT15_OUT,));
  __SET_VAR(data__->,OVERFLOWVALVEOPEN,,__GET_VAR(data__->OVERFLOWSENSOR,));
  __SET_VAR(data__->,_TMP_LT46_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->TURBIDITYSENSOR,),
    (INT)__GET_VAR(data__->TURBIDITYTHRESHOLD,)));
  __SET_VAR(data__->,_TMP_LT38_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->TSSSENSOR,),
    (INT)__GET_VAR(data__->TSSTHRESHOLD,)));
  __SET_VAR(data__->,_TMP_AND44_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_LT46_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_LT38_OUT,)));
  __SET_VAR(data__->,FILTRATIONCONTROL,,(__GET_VAR(data__->PHVALID,) && __GET_VAR(data__->_TMP_AND44_OUT,)));
  __SET_VAR(data__->,_TMP_LT40_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->PHUPPER,),
    (INT)__GET_VAR(data__->PHSENSOR,)));
  __SET_VAR(data__->,_TMP_GT56_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->PHSENSOR,),
    (INT)__GET_VAR(data__->PHLOWER,)));
  __SET_VAR(data__->,_TMP_AND57_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_LT40_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_GT56_OUT,)));
  __SET_VAR(data__->,PHVALID,,__GET_VAR(data__->_TMP_AND57_OUT,));
  __SET_VAR(data__->,PUMPSTATUS,,(__GET_VAR(data__->PHVALID,) && __GET_VAR(data__->_TMP_AND44_OUT,)));
  __SET_VAR(data__->,_TMP_LT50_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->UVUPPER,),
    (INT)__GET_VAR(data__->UVPOWER,)));
  __SET_VAR(data__->,_TMP_GT65_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->UVPOWER,),
    (INT)__GET_VAR(data__->UVLOWER,)));
  __SET_VAR(data__->,_TMP_AND52_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_LT50_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_GT65_OUT,)));
  __SET_VAR(data__->,OUTLETCONTROL,,(__GET_VAR(data__->DISINFECTANTSTATUS,) && __GET_VAR(data__->_TMP_AND52_OUT,)));
  __SET_VAR(data__->,_TMP_LT62_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->UVLOWER,),
    (INT)__GET_VAR(data__->UVPOWER,)));
  __SET_VAR(data__->,UVINCREASESTRENGTH,,__GET_VAR(data__->_TMP_LT62_OUT,));
  __SET_VAR(data__->,_TMP_GT72_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->UVPOWER,),
    (INT)__GET_VAR(data__->UVUPPER,)));
  __SET_VAR(data__->,UVLOWERSTRENGTH,,__GET_VAR(data__->_TMP_GT72_OUT,));
  __SET_VAR(data__->,DISINFECTANTSTATUS,,__GET_VAR(data__->_TMP_LT62_OUT,));
  __SET_VAR(data__->,_TMP_SUB39_OUT,,SUB__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->INFLOWSENSOR,),
    (INT)__GET_VAR(data__->CONST10000,)));

  goto __end;

__end:
  return;
} // SLUDGE_body__() 





void INFLUENT_init__(INFLUENT *data__, BOOL retain) {
  __INIT_VAR(data__->INFLUENTWATERFLOW,0,retain)
  __INIT_VAR(data__->EFFLUENTWATERFLOW,0,retain)
  __INIT_VAR(data__->AIRFLOW,0,retain)
  __INIT_VAR(data__->PRETREATMENTUNITFLOW,0,retain)
  __INIT_VAR(data__->CLARIFIERWATERDEPTH,4,retain)
  __INIT_VAR(data__->CLARIFIERWATERTEMP,0,retain)
  __INIT_VAR(data__->AEROBICSURFACE,0,retain)
  __INIT_VAR(data__->AEROBICREACTORAIRFLOW,0,retain)
  __INIT_VAR(data__->AEROBICWATERLEVEL,0,retain)
  __INIT_VAR(data__->TSS,0,retain)
  __INIT_VAR(data__->SANDCONTAINERFLOW,0,retain)
  __INIT_VAR(data__->SANDWATERLEVELHIGH,0,retain)
  __INIT_VAR(data__->AIRBLOWER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FERROUSCHEMICALDEPLOY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PRETREATINLETCONTROLSTATUS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PRETREATOUTLETCONTROLSTATUS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SCREENINGCONTAINEREFFLUENTVALVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SANDCONTAINEREFFLUENTVALVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SCREENINGCONTSLUDGEEFFLUENTVALVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLARIFIEROUTLETVALVE,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AIRMINFLOW,49923,retain)
  __INIT_VAR(data__->AIRMAXFLOW,186302,retain)
  __INIT_VAR(data__->TEMPMIN,17,retain)
  __INIT_VAR(data__->TEMPMAX,30,retain)
  __INIT_VAR(data__->DESIGNFLOW,10000,retain)
  __INIT_VAR(data__->DRYWEATHERFLOW,27702,retain)
  __INIT_VAR(data__->TSSTHRESHOLD,275,retain)
  __INIT_VAR(data__->BOD5THRESHOLD,313,retain)
  __INIT_VAR(data__->INFLUENTFLOWVALVESTATUS,0,retain)
  __INIT_VAR(data__->CLARIFIERWATERDEPTHTHRESHOLD,4,retain)
  __INIT_VAR(data__->CLARIFIERSURFACE,144,retain)
  __INIT_VAR(data__->_TMP_LE7_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT15_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT17_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT21_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT27_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void INFLUENT_body__(INFLUENT *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_LE7_OUT,,LE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->INFLUENTWATERFLOW,),
    (INT)__GET_VAR(data__->DRYWEATHERFLOW,)));
  __SET_VAR(data__->,PRETREATINLETCONTROLSTATUS,,__GET_VAR(data__->_TMP_LE7_OUT,));
  __SET_VAR(data__->,SANDCONTAINEREFFLUENTVALVE,,__GET_VAR(data__->SANDWATERLEVELHIGH,));
  __SET_VAR(data__->,SCREENINGCONTAINEREFFLUENTVALVE,,__GET_VAR(data__->SANDWATERLEVELHIGH,));
  __SET_VAR(data__->,_TMP_GT15_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CLARIFIERWATERDEPTH,),
    (INT)__GET_VAR(data__->CLARIFIERWATERDEPTHTHRESHOLD,)));
  __SET_VAR(data__->,CLARIFIEROUTLETVALVE,,__GET_VAR(data__->_TMP_GT15_OUT,));
  __SET_VAR(data__->,_TMP_LT17_OUT,,LT__BOOL__LINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (LINT)__GET_VAR(data__->AEROBICREACTORAIRFLOW,),
    (LINT)__GET_VAR(data__->AIRMINFLOW,)));
  __SET_VAR(data__->,AIRBLOWER,,__GET_VAR(data__->_TMP_LT17_OUT,));
  __SET_VAR(data__->,_TMP_GT21_OUT,,GT__BOOL__LINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (LINT)__GET_VAR(data__->AEROBICREACTORAIRFLOW,),
    (LINT)__GET_VAR(data__->AIRMAXFLOW,)));
  __SET_VAR(data__->,AIRBLOWER,,!(__GET_VAR(data__->_TMP_GT21_OUT,)));
  __SET_VAR(data__->,_TMP_GT27_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->TSS,),
    (INT)__GET_VAR(data__->TSSTHRESHOLD,)));
  __SET_VAR(data__->,FERROUSCHEMICALDEPLOY,,__GET_VAR(data__->_TMP_GT27_OUT,));

  goto __end;

__end:
  return;
} // INFLUENT_body__() 





