#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;

class VirtualContainers
{
private:
	int length;
	int width;
	int height;
	int weight;
public:
	VirtualContainers();
	VirtualContainers(int vlength, int vwidth, int vheight, int vweight);
	static int num_of_containers;
	static int show_num_of_containers()
	{ 
		cout << " *** Num of containers *** " << num_of_containers << endl; 
		return num_of_containers;
	}
	virtual void Show_Containers() const;

};
VirtualContainers::VirtualContainers()
{
	num_of_containers++;
}
VirtualContainers::VirtualContainers(int vlength, int vwidth, int vheight, int vweight)
{
	num_of_containers++;
	this->length = vlength;
	this->width = vwidth;
	this->height =vheight;
	this->weight = vweight;
}

void VirtualContainers::Show_Containers() const
{
	cout << "***** VirtualContainers *****" << endl;
	cout << "** Length ** : " << this->length << " cm " << endl;
	cout << "** Width  ** : " << this->width << " cm " << endl;
	cout << "** Height ** : " << this->height << " cm " << endl;
	cout << "** Weight ** : " << this->weight << " Kg " << endl;
}
class PaperContainer : public VirtualContainers
{
private:
	string material;
	string color;
public:
	PaperContainer();
	PaperContainer(string, string, int, int, int, int);
	virtual void Show_Containers() const;

};
PaperContainer::PaperContainer()
{
}
PaperContainer::PaperContainer(string pmaterial, string pcolor, 
							   int vlength, int vwidth, int vheight, int vweight)
							   :VirtualContainers(vlength, vwidth, vheight,vweight)
{
	this->material = pmaterial;
	this->color = pcolor;
}

void PaperContainer::Show_Containers() const
{
	VirtualContainers::Show_Containers();
	cout << "++++++ PaperContainer ++++++" << endl;
	cout << "+++ Material +++ : " << this->material;
	cout << "+++ Color    +++ : " << this->color;
}
class GlassContainer : public VirtualContainers
{
private:
	string glass_type;
	string producer;
public:
	GlassContainer();
	GlassContainer(string, string, int, int, int, int);
	virtual void Show_Containers() const;
};
GlassContainer::GlassContainer()
{
}
GlassContainer::GlassContainer(string gglass_type, string gproducer, 
							   int vlength, int vwidth, int vheight, int vweight)
							   :VirtualContainers(vlength, vwidth, vheight,vweight)
{
	this->glass_type = gglass_type;
	this->producer = gproducer;

}
void GlassContainer::Show_Containers() const
{
	VirtualContainers::Show_Containers();
	cout << "##### GlassContainer #####" << endl;
	cout << "### Glass Type ### : " << this->glass_type << endl;
	cout << "### Producer   ### : " << this->producer << endl;
}
int VirtualContainers::num_of_containers=0;
int main(void)
{
	PaperContainer pBox("¥Ë·«¯È", "¬õ¦â", 100, 50, 50, 2);
	GlassContainer gBox("³z©ú¬Á¼þ", "¼yÂ×¹ê·~", 50,50,30,10);
	pBox.Show_Containers();
	gBox.Show_Containers();
	VirtualContainers::show_num_of_containers();
//	cout << "Total containers : " << VirtualContainers::Show_Containers() << endl;
	return 1;

}