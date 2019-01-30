#include <fhc/hilbert.h>

#include "mathlink.h"
#include "WolframLibrary.h"

/* Return the version of Library Link */
DLLEXPORT mint WolframLibrary_getVersion( ) {
	return WolframLibraryVersion;
}

/* Initialize Library */
DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) {
	return LIBRARY_NO_ERROR;
}

/* Uninitialize Library */
DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) {
	return;
}

DLLEXPORT int fast_hilbert_curve_wstp( WolframLibraryData libData, MLINK lp)
{
	int len;
	if ( !MLTestHead( lp, "List", &len)) 
		return LIBRARY_FUNCTION_ERROR;
	if ( len != 1) 
		return LIBRARY_FUNCTION_ERROR;

	// Argument
	uint64_t i ;

	if ( !MLGetInteger64(lp, &i) )
		return LIBRARY_FUNCTION_ERROR;

	fhc_point p;
	p = fhc_hilbert(i);

	if ( !MLPutInteger32List(lp, (int *)&p, 2) )
		return LIBRARY_FUNCTION_ERROR;

	return LIBRARY_NO_ERROR;
}
