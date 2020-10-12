 class Context 
 {
 public: 
 	virtual void moveTo(int x, int y) = 0;
 	virtual void lineTo(int x, int y) = 0;
 	virtual void arcTo(int x, int y, int r) = 0;

 protected:
 	~Context();
 };

class Shape 
{ 
public:
	~Shape();

	virtual void draw(Context &) = 0;
};

class SvgContext:
	public Context 
{
public: 
	SvgContext(const char * name): 
	out_(fopen(name, "w")) 
	{}

	virtual void moveTo(int x, int y);
	virtual void lineTo(int x, int y);
	virtual void arcTo(int x, int y, int r);

private: 
	FILE * out_;
};

void drawShapes(char * file, Shape * shapes, size_t count) 
{ 
	SvgContext ctx(file);

	for (size_t i = 0; i < count; i) { 
		shapes[i].draw(ctx); 
	} 
} 
