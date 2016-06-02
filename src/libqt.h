#include<QApplication>
#include<QWidget>
#include<QTimer>

//============================================================
//==================== Widget ================================
//============================================================

class StzQtWidget : public QWidget{
  Q_OBJECT
 public:
  StzQtWidget(QWidget* parent);
  int width;
  int height;
  int listener;
  QSize sizeHint() const;
 protected:
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent* event);
  void mouseReleaseEvent(QMouseEvent* event);
  void mouseMoveEvent(QMouseEvent* event);  
  void keyPressEvent(QKeyEvent *event);
};

//============================================================
//==================== Timer =================================
//============================================================

class StzQtTimer : public QTimer{
  Q_OBJECT
 public:
  int callback;
  StzQtTimer(int callback);
 private Q_SLOTS:
  void tick();
};
