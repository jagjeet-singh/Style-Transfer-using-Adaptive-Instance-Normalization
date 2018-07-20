#include <string.h>

#include <ysgl.h>
#include <ysglsldrawfontbitmap.h>

#include "gui.h"



CheapGUI::CheapGUI()
{
	needRedraw=false;
	lastClick=nullptr;
}
CheapGUI::Text *CheapGUI::AddText(int x0,int y0,int wid,int hei,const char label[])
{
	std::shared_ptr <Widget> widgetPtr(new Text);
	widgetList.push_back(widgetPtr);
	auto btnPtr=dynamic_cast <Text *>(widgetPtr.get());

	btnPtr->label=label;
	btnPtr->x0=x0;
	btnPtr->y0=y0;
	btnPtr->wid=wid;
	btnPtr->hei=hei;
	btnPtr->guiPtr=this;

	return btnPtr;
}
CheapGUI::PushButton *CheapGUI::AddPushButton(int x0,int y0,int wid,int hei,const char label[])
{
	std::shared_ptr <Widget> widgetPtr(new PushButton);
	widgetList.push_back(widgetPtr);
	auto btnPtr=dynamic_cast <PushButton *>(widgetPtr.get());

	btnPtr->label=label;
	btnPtr->x0=x0;
	btnPtr->y0=y0;
	btnPtr->wid=wid;
	btnPtr->hei=hei;
	btnPtr->guiPtr=this;

	return btnPtr;
}
CheapGUI::CheckBox *CheapGUI::AddCheckBox(int x0,int y0,int wid,int hei,const char label[])
{
	std::shared_ptr <Widget> widgetPtr(new CheckBox);
	widgetList.push_back(widgetPtr);
	auto btnPtr=dynamic_cast <CheckBox *>(widgetPtr.get());

	btnPtr->label=label;
	btnPtr->x0=x0;
	btnPtr->y0=y0;
	btnPtr->wid=wid;
	btnPtr->hei=hei;
	btnPtr->guiPtr=this;

	return btnPtr;
}
void CheapGUI::SetRadioButtonGroup(const std::vector <CheckBox *> &grp)
{
	for(auto btnPtr : grp)
	{
		btnPtr->SetRadioButtonGroup(grp);
	}
}
void CheapGUI::Draw(void) const
{
	for(auto w : widgetList)
	{
		if(true!=w->hide)
		{
			w->Draw();
		}
	}
	needRedraw=false;
}

void CheapGUI::NotifyMousePosition(int mx,int my)
{
}

void CheapGUI::NotifyLButtonUp(int mx,int my)
{
	for(auto w : widgetList)
	{
		if(true!=w->hide &&
		   w->x0<=mx && mx<=w->x0+w->wid && w->y0<=my && my<=w->y0+w->hei)
		{
			w->Clicked();
			lastClick=w.get();
		}
	}
}
CheapGUI::Widget *CheapGUI::GetLastClicked(void)
{
	auto lc=lastClick;
	lastClick=nullptr;
	return lc;
}
const CheapGUI::Widget *CheapGUI::PeekLastClicked(void) const
{
	return lastClick;
}

CheapGUI::Widget *CheapGUI::PeekLastClicked(void)
{
	return lastClick;
}


////////////////////////////////////////////////////////////

CheapGUI::Widget::Widget()
{
	r=0;
	g=0;
	b=255;
	a=255;
	hide=false;
}

void CheapGUI::Widget::Show(void)
{
	if(true==hide)
	{
		hide=false;
		guiPtr->needRedraw=true;
	}
}
void CheapGUI::Widget::Hide(void)
{
	if(true!=hide)
	{
		hide=true;
		guiPtr->needRedraw=true;
	}
}

void CheapGUI::Widget::SetColor(int r,int g,int b,int a)
{
	this->r=r;
	this->g=g;
	this->b=b;
	this->a=a;
}

////////////////////////////////////////////////////////////

void CheapGUI::Text::SetText(const char str[])
{
	label=str;
	guiPtr->needRedraw=true;
}
/* virtual */ void CheapGUI::Text::Draw()
{
	auto *renderer=YsGLSLSharedBitmapFontRenderer();
	YsGLSLUseBitmapFontRenderer(renderer);
	auto fontH=YsGLSLGetBitmapFontRendererFontHeight(renderer);
	auto spaceH=(hei-fontH)/2;
	YsGLSLSetBitmapFontRendererColor4ub(renderer,this->r,this->g,this->b,this->a);
	YsGLSLRenderBitmapFontString2D(renderer,x0+8,y0+hei-spaceH,label.c_str());
	YsGLSLEndUseBitmapFontRenderer(renderer);
}

////////////////////////////////////////////////////////////

CheapGUI::Button::Button()
{
	heldDown=false;
}

////////////////////////////////////////////////////////////

/* virtual */ void CheapGUI::PushButton::Draw()
{
	{
		auto renderer=YsGLSLSharedPlain2DRenderer();
		YsGLSLUsePlain2DRenderer(renderer);

		YsGLSLUseWindowCoordinateInPlain2DDrawing(renderer,1);

		const float col[4]={0,0,1,1};
		YsGLSLSetPlain2DRendererUniformColor(renderer,col);

		float vertex[8]=
		{
			(float)x0    ,(float)y0,
			(float)x0+wid,(float)y0,
			(float)x0+wid,(float)y0+hei,
			(float)x0    ,(float)y0+hei,
		};
		YsGLSLDrawPlain2DPrimitiveVtxfv(renderer,GL_LINE_LOOP,4,vertex);

		YsGLSLEndUsePlain2DRenderer(renderer);
	}
	{
		auto *renderer=YsGLSLSharedBitmapFontRenderer();
		YsGLSLUseBitmapFontRenderer(renderer);
		auto fontH=YsGLSLGetBitmapFontRendererFontHeight(renderer);
		auto spaceH=(hei-fontH)/2;
		auto textW=YsGLSLGetBitmapFontRendererFontWidth(renderer)*label.size();
		auto spaceW=(wid-textW)/2;
		YsGLSLSetBitmapFontRendererColor4ub(renderer,this->r,this->g,this->b,this->a);
		YsGLSLRenderBitmapFontString2D(renderer,x0+spaceW,y0+hei-spaceH,label.c_str());
		YsGLSLEndUseBitmapFontRenderer(renderer);
	}
}

////////////////////////////////////////////////////////////

CheapGUI::CheckBox::CheckBox()
{
	checked=false;
}

void CheapGUI::CheckBox::SetCheck(bool c)
{
	if(c!=checked)
	{
		checked=c;
		guiPtr->needRedraw=true;
	}
}

bool CheapGUI::CheckBox::GetCheck(void) const
{
	return checked;
}

void CheapGUI::CheckBox::SetRadioButtonGroup(const std::vector <CheckBox *> &grp)
{
	this->radioBtnGrp=grp;
}

/* virtual */ void CheapGUI::CheckBox::Draw()
{
	const float rectVertex[8]=
	{
		(float)x0    ,(float)y0,
		(float)x0+wid,(float)y0,
		(float)x0+wid,(float)y0+hei,
		(float)x0    ,(float)y0+hei,
	};

	{
		auto renderer=YsGLSLSharedPlain2DRenderer();
		YsGLSLUsePlain2DRenderer(renderer);

		YsGLSLUseWindowCoordinateInPlain2DDrawing(renderer,1);

		if(true==checked)
		{
			const float col[4]=
			{
				float(this->r)/255.0f,
				float(this->g)/255.0f,
				float(this->b)/255.0f,
				1.0f
			};
			YsGLSLSetPlain2DRendererUniformColor(renderer,col);
			YsGLSLDrawPlain2DPrimitiveVtxfv(renderer,GL_TRIANGLE_FAN,4,rectVertex);
		}

		const float col[4]={0,0,1,1};
		YsGLSLSetPlain2DRendererUniformColor(renderer,col);
		YsGLSLDrawPlain2DPrimitiveVtxfv(renderer,GL_LINE_LOOP,4,rectVertex);
		YsGLSLEndUsePlain2DRenderer(renderer);
	}
	{
		auto *renderer=YsGLSLSharedBitmapFontRenderer();
		YsGLSLUseBitmapFontRenderer(renderer);
		auto fontH=YsGLSLGetBitmapFontRendererFontHeight(renderer);
		auto spaceH=(hei-fontH)/2;
		auto textW=YsGLSLGetBitmapFontRendererFontWidth(renderer)*label.size();
		auto spaceW=(wid-textW)/2;
		if(true!=checked)
		{
			YsGLSLSetBitmapFontRendererColor4ub(renderer,this->r,this->g,this->b,this->a);
		}
		else
		{
			YsGLSLSetBitmapFontRendererColor4ub(renderer,255-this->r,255-this->g,255-this->b,this->a);
		}
		YsGLSLRenderBitmapFontString2D(renderer,x0+spaceW,y0+hei-spaceH,label.c_str());
		YsGLSLEndUseBitmapFontRenderer(renderer);
	}
}

/* virtual */ void CheapGUI::CheckBox::Clicked(void)
{
	if(0==radioBtnGrp.size())
	{
		if(true==checked)
		{
			checked=false;
		}
		else
		{
			checked=true;
		}
		guiPtr->needRedraw=true;
	}
	else
	{
		if(true!=checked)
		{
			for(auto btnPtr : radioBtnGrp)
			{
				btnPtr->SetCheck(false);
			}
			checked=true;
			guiPtr->needRedraw=true;
		}
	}
}
