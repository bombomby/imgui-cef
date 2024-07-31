#include <iostream>

#include <include/cef_app.h>
#include <include/cef_client.h>
#include <include/cef_render_handler.h>
#include <include/cef_life_span_handler.h>
#include <include/cef_load_handler.h>
#include <include/wrapper/cef_helpers.h>

// Program entry-point function.
int main( int argc, char* argv[] )
{
	// Load the CEF framework library at runtime instead of linking directly
	// as required by the macOS sandbox implementation.
	CefScopedLibraryLoader library_loader;
	if( !library_loader.LoadInHelper() )
		return 1;

	// Structure for passing command-line arguments.
	// The definition of this structure is platform-specific.
	CefMainArgs main_args( argc, argv );

	// Implementation of the CefApp interface.
	CefRefPtr< MyApp > app( new MyApp );

	// Execute the sub-process logic. This will block until the sub-process should exit.
	return CefExecuteProcess( main_args, app.get() );
}
