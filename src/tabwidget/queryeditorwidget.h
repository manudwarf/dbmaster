#ifndef QUERYEDITORWIDGET_H
#define QUERYEDITORWIDGET_H

#include "abstracttabwidget.h"
#include "resultview/querydataprovider.h"

#include "ui_queryeditorwidget.h"

#include <QSqlError>
#include <QSqlResult>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QStatusBar>

class QueryEditorWidget: public AbstractTabWidget, Ui::QueryEditorWidget {
Q_OBJECT
public:
  QueryEditorWidget(QWidget* = 0);

  Actions       availableActions();
  int           confirmCloseAll();
  QString       file();
  QIcon         icon();
  QString       id();
  bool          isSaved();
  void          print();
  QPrinter     *printer();
  void          saveAs(QString = QString::null);
  QTextEdit    *textEdit();
  QString       title();

public slots:
  void copy();
  void cut();
  void lowerCase();
  void open( QString );
  void paste();
  void redo();
  void refresh();
  void reload();
  bool save();
  void selectAll();
  void undo();
  void upperCase();

signals:
  void fileChanged(QString);

private:
  void closeEvent(QCloseEvent *event);
  bool confirmClose();
  QSqlDatabase* currentDb();
  void keyPressEvent(QKeyEvent *event);
  QString queryText();
  void reloadFile();
  void setFilePath(QString);
  void setupConnections();
  void setupWidgets();
  void showEvent(QShowEvent *event);

  Actions               baseActions;
  QueryDataProvider* dataProvider;
  QString               filePath;
  int                   oldCount;
  int                   page;
  QToolButton*          resultButton;
  QStatusBar           *statusBar;
  // QFileSystemWatcher   *watcher;

private slots:
  void checkDbOpen();
  void onFileChanged(QString path);
  void queryError();
  void querySuccess();
  void start();
  // void validateQuery();
};

#endif // QUERYEDITORWIDGET_H
