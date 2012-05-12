class RectangularGrid
{
public:
  long long countRectangles(int width, int height)
  {
    long long ret = 0;
    int square_offset = 0;
    for (int i = width; i > 0; --i)
      for (int j = height; j > 0; --j)
	{
	  square_offset = (i <= j) ? i : j;
	  ret += i * j - square_offset;
	}
    return ret;
  }
};
