#ifndef H_FIELDTYPE
#define H_FIELDTYPE

class fieldType
{
        private:
                int row;
                int length;
        public:
                char fieldArray[40][100];
                fieldType();
                int getRow();
                int getLength();
                void draw();


};
#endif // H_FIELDTYPE
