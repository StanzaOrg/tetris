#include<QApplication>
#include<QWidget>
#include "libqt.h"

//============================================================
//==================== Widget ================================
//============================================================

StzQtWidget::StzQtWidget(QWidget* parent) : QWidget(parent) {
}

//============================================================
//=================== C Bindings =============================
//============================================================

extern "C" {  
  QApplication* QApplication_new (int argc, char* argv[]){return new QApplication(argc, argv);}
  void QApplication_delete (QApplication* x){delete x;}
  int QApplication_exec (QApplication* x){return x->exec();}

  StzQtWidget* QtWidget_new (QWidget* parent) {return new StzQtWidget(parent);}
  void QtWidget_delete (StzQtWidget* x){delete x;}
  void QtWidget_show (StzQtWidget* x){x->show();}
}
