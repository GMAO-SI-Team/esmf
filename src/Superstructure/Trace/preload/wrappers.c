/**
 *
 * wrappers.c
 *
 */

#include <stdio.h>

extern "C" {

  static int traceInitialized = 0;
  
  /**
   * Called into from ESMCI_Trace.C when the trace
   * is opened and can receive events.  The linker will wrap
   * the c_esmftrace_notify_wrappers() function with this one
   * to catch the notification.
   */
  void __wrap_c_esmftrace_notify_wrappers(int initialized) {
    if (initialized == 1) {
      printf("ESMF Tracing enabled with static instrumentation\n");
      traceInitialized = 1;
    }
    else {
      traceInitialized = 0;
    }
  }

   
  int __wrap_c_esmftrace_isinitialized() {
    return traceInitialized;
  }  
  
  
}