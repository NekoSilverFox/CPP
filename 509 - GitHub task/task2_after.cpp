
 //after
 class Context 
 {
 public: 
 	virtual void moveTo(int x, int y) = 0;
 	virtual void lineTo(int x, int y) = 0;
 	virtual void arcTo(int x, int y, int r) = 0;

 protected:
 	virtual ~Context();
 };

class Shape 
{ 
public:
    using ShapePtr = std::shared_ptr<Shape>;
	virtual ~Shape();
	virtual void draw(Context &) = 0;
};


class SvgContext:
	public Context 
{
public: 
	SvgContext(const char * name): 
	out_(fopen(name, "w")) 
	{
        if(!out_)
        {
            throw std::runtime_error("Can not open file.\n");
            return 1;
        }
    }

    virtual ~SvgContext()
    {
        fclose(out_);
    }

	void moveTo(int x, int y) override;
	void lineTo(int x, int y) override;
	void arcTo(int x, int y, int r) override;

private:
	FILE * out_;
};

void drawShapes(char * file, shape::ShapePtr* shapes, size_t count) 
{ 

    if(!file)
    {
        throw std::invalid_argument("File name is empty.\n");
    }
    if(!shapes)
    {
        throw std::invalid_argument("Shape is empty.\n");
    }

	SvgContext ctx(file);

	for (size_t i = 0; i < count; ++i) { 
		shapes[i]->draw(ctx); 
	} 
}