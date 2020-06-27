#include <gd.h>
#include <zlib.h>

int main()
{
	gdImagePtr gdImg = gdImageCreateFromPngPtr(8, NULL); //Utilize libpng
	
	z_stream s;
	inflateInit2(&s, -MAX_WBITS); // Utilize zlib
	inflate(&s, Z_FINISH);
	inflateEnd(&s);
	
	gdImageDestroy(gdImg);
	return 0;
}
