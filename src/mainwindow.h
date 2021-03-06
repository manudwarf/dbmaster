#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dialogs/aboutdialog.h"
#include "dialogs/configdialog.h"
#include "dialogs/dbdialog.h"
#include "dialogs/searchdialog.h"
#include "ui_mainwindow.h"
#include "plugins/plugindialog.h"
#include "tabwidget/queryeditorwidget.h"
#include "wizards/newdbwizard.h"

#include <QSqlDatabase>
#include <QMainWindow>
#include <QUrl>
#include <QWidget>

class MainWindow: public QMainWindow, public Ui::MainWindowClass {
Q_OBJECT

public:
  MainWindow(QWidget *parent =0);
  ~MainWindow();

  static DbDialog      *dbDialog;
  static NewDbWizard   *dbWizard;
  static MainWindow* instance;
  static PluginDialog  *pluginDialog;

signals:
  void indentationChanged();

public slots:
  void addRecentFile(QString file);
  void createDatabase();
  QueryEditorWidget*  newQuery();
  void openQuery();
  void openQuery(QString file);
  void openSchema(QSqlDatabase *db, QString schema);
  void openTable(QSqlDatabase *db, QString table);
  void refreshTab();
  void refreshRecent();
  void reloadDbList();
  void saveQuery();
  void saveQueryAs();
  void toggleLeftPanel();

private:
  void                closeEvent(QCloseEvent*);
  AbstractTabWidget*  currentTab();
  void                loadSettings(QSettings* s);
  void                removeRecentFile(QString file);
  void                saveSettings();
  void                setupActionMap();
  void                setupConnections();
  void                setupDbActions();
  void                setupDialogs();
  void                setupDocks(QSettings *s);
  void                setupIcons();
  QToolButton*        setupLogButton(QAction* logAct);
  void                setupQueriesStatusLabel();
  void                setupRecentFiles(QSettings* s);
  void                setupWidgets();

  AboutDialog        *aboutDial;
  QMap<AbstractTabWidget::Action, QAction*> actionMap;
  ConfigDialog       *confDial;
  QString             lastPath;
  SearchDialog       *searchDialog;
  QLabel             *queriesStatusLabel;
  QList<QAction*>     recentActions;
  QStringList         recentFiles;

private slots:
  void clearRecent();
  void closeCurrentTab();
  void closeSender();
  void closeTab(int nb);
  void copy();
  void cut();
  void lowerCase();
  void nextTab();
  void openHomepageLink(QUrl url);
  void openRecent();
  void paste();
  void previousTab();
  void print();
  void redo();
  void refreshTabActions();
  void search();
  void selectAll();
  void setIndentation2Spaces();
  void setIndentation4Spaces();
  void setIndentation8Spaces();
  void setIndentationSpaces(bool enabled);
  void undo();
  void updateDbActions();
  void upperCase();
};

#endif // MAINWINDOW_H
