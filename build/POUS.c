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
  __INIT_VAR(data__->OVERFLOWSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUMPSTATUS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GASHIGHVOLUMEALERT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SLUDGEOUTPUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->THICKENINGPUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SOLIDWASTEALARM,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->THICKENINGPUMP0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DIGESTERPUMP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HOTWATERPUMPIN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HOTWATERPUMPOUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GASPUMPTOTRANSPORT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DISSOLVEDO2,0,retain)
  __INIT_VAR(data__->O2DEMAND,0,retain)
  __INIT_VAR(data__->_TMP_GT8_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT21_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void SLUDGE_body__(SLUDGE *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,SLUDGEOUTPUMP,,__GET_VAR(data__->PUMPSTATUS,));
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

  goto __end;

__end:
  return;
} // SLUDGE_body__() 





