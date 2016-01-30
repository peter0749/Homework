#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class ProductCategory
{
private:
	string type;
	string producer;
	string sequence;
	int unit_cost;
	static int Category_num;
public:
	ProductCategory();
	ProductCategory(string ptype, string pproducer, string psequence, int uni_cost);
	virtual void Show_Product_Details() const;
	static int Show_Category_Num()
	{ 
		cout << "*** Num of Category ***" << Category_num << endl; 
		return Category_num;
	}
};

ProductCategory::ProductCategory()
{
	Category_num++;
}
ProductCategory::ProductCategory(string ptype, string pproducer, string psequence, int pcost)
{
	Category_num++;
	this->type = ptype;
	this->producer = pproducer;
	this->sequence = psequence;
	this->unit_cost =pcost;
}

void ProductCategory::Show_Product_Details() const
{
	cout << "**** Show Product Details ****" << endl;
	cout << "���~���A�G  " << this->type << endl;
	cout << "�s�y�ӡG    " << this->producer << endl;
	cout << "���A�Ǹ��G  " << this->sequence << endl;
	cout << "�s�y�����G  " << this->unit_cost << endl;
}
class FoodProduct: public ProductCategory
{
private:
	int Preserve_Year;
	int weight;
	string product_id;
	string product_name;
public:
    FoodProduct();
	FoodProduct(int fp_year, int fweight, string fp_id, string fp_name, 
		string ptype, string pproducer, string psequence, int pcost);
	virtual void Show_Product_Details() const;

};
FoodProduct::FoodProduct()
{
}
FoodProduct::FoodProduct(int fp_year, int fweight, string fp_id, string fp_name, 
						 string ptype, string pproducer, string psequence, int pcost):
ProductCategory(ptype, pproducer, psequence, pcost)
{
	this->Preserve_Year = fp_year;
	this->weight = fweight;
	this->product_id = fp_id;
	this->product_name = fp_name;
}
void FoodProduct::Show_Product_Details() const
{
	ProductCategory::Show_Product_Details();
	cout << "##### Show Food Product Details #####" << endl;
	cout << "���~�W�١G   " << this->product_name << endl;
	cout << "���~�Ǹ��G   " << this->product_id << endl;
	cout << "�O�s�~���G   " << this->Preserve_Year << " �~" << endl;
	cout << "�b���G       " << this->weight << " ���J" << endl;
}

int ProductCategory::Category_num=0;
int main(void)
{
	FoodProduct pancake(3, 1000, "FP-001-001", "�P�毻", "���~��", "�p�ع�~", "UC-001-001", 20);
	FoodProduct soda_powder(2, 500, "FP-001-002", "Ĭ����", "���~��", "�p�ع�~", "UC-001-002", 10);
	pancake.Show_Product_Details();
	soda_powder.Show_Product_Details();


	return 1;
}