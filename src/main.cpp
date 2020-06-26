#include <coreinit/memdefaultheap.h>
#include <coreinit/thread.h>
#include <gui/GuiImageData.h>
#include <gui/memory.h>
#include <zlib.h>

int main()
{
	libgui_memoryInitialize();
	GuiImageData *testData = new GuiImageData(NULL, 1, GX2_TEX_CLAMP_MODE_WRAP, GX2_SURFACE_FORMAT_UNORM_R8_G8_B8_A8); //Utilize libpng
	
	z_stream s;
	inflateInit2(&s, -MAX_WBITS); // Utilize zlib
	inflate(&s, Z_FINISH);
	inflateEnd(&s);
	
	delete testData;
	libgui_memoryRelease();
	return 0;
}
