#include "imageeditor.h"
#include <QApplication>
#include <omp.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* QTextStream cout(stdout);
    omp_set_num_threads(10);
    cout<<"Here I am/n";
    #pragma omp parallel num_threads(3)
    {
        cout<<"openmp parallel "<<omp_get_num_threads()<<"\n";
    }
    */
   /// cout<<"openmp working "<<omp_get_num_threads()<<"\n";
    ImageEditor w;
    w.show();
    return a.exec();
}
