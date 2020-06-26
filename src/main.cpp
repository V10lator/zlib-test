#include <coreinit/memdefaultheap.h>
#include <coreinit/memory.h>
#include <coreinit/thread.h>
#include <gui/GuiImage.h>
#include <gui/GuiImageData.h>
#include <gui/memory.h>
#include <zlib.h>

#include <test_png.h>

int main()
{
	libgui_memoryInitialize();
	GuiImageData *testData = new GuiImageData(test_png, test_png_size, GX2_TEX_CLAMP_MODE_WRAP, GX2_SURFACE_FORMAT_UNORM_R8_G8_B8_A8);
	GuiImage *testImage = new GuiImage(testData);
	
	z_stream s;
	OSBlockSet(&s, 0x00, sizeof(z_stream));
	s.next_in = (Bytef*)NULL;
	s.avail_in = (uInt)1;
	s.next_out = (Bytef*)NULL;
	s.avail_out = (uInt)1;
	inflateInit2(&s, -MAX_WBITS);
	inflate(&s, Z_FINISH);
	inflateEnd(&s);
	
	delete testImage;
	delete testData;
	libgui_memoryRelease();
	return 0;
}
