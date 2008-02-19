#ifndef FindDialog_H
#define FindDialog_H

#include <QDialog>

#include "ui_Find.h"
#include "ui_Replace.h"

class TeXDocument;
class QTextEdit;

class FindDialog : public QDialog, private Ui::FindDialog
{
	Q_OBJECT

public:
	FindDialog(QTextEdit *document);

	static DialogCode doFindDialog(QTextEdit *document);

private slots:
	void toggledRegexOption(bool checked);
	void toggledSelectionOption(bool checked);
	void checkRegex(const QString& str);

private:
	void init(QTextEdit *document);
};

class ReplaceDialog : public QDialog, private Ui::ReplaceDialog
{
	Q_OBJECT

public:
	ReplaceDialog(QTextEdit *parent);
	
	typedef enum {
		Cancel,
		ReplaceOne,
		ReplaceAll
	} DialogCode;
	
	static DialogCode doReplaceDialog(QTextEdit *document);

private slots:
	void toggledRegexOption(bool checked);
	void toggledSelectionOption(bool checked);
	void checkRegex(const QString& str);
	void clickedReplace();
	void clickedReplaceAll();

private:
	void init(QTextEdit *document);
};

#endif