/*
 * nheko Copyright (C) 2017  Konstantinos Sideris <siderisk@auth.gr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QHBoxLayout>
#include <QLabel>
#include <QSharedPointer>
#include <QVBoxLayout>
#include <QWidget>

#include "FlatButton.h"
#include "InputValidator.h"
#include "MatrixClient.h"
#include "RaisedButton.h"
#include "TextField.h"

class RegisterPage : public QWidget
{
	Q_OBJECT

public:
	RegisterPage(QSharedPointer<MatrixClient> client, QWidget *parent = 0);
	~RegisterPage();

signals:
	void backButtonClicked();

private slots:
	void onBackButtonClicked();
	void onRegisterButtonClicked();

	// Display registration specific errors to the user.
	void registerError(const QString &msg);

private:
	QVBoxLayout *top_layout_;

	QHBoxLayout *back_layout_;
	QHBoxLayout *logo_layout_;
	QHBoxLayout *button_layout_;

	QLabel *logo_;
	QLabel *error_label_;

	FlatButton *back_button_;
	RaisedButton *register_button_;

	QWidget *form_widget_;
	QHBoxLayout *form_wrapper_;
	QVBoxLayout *form_layout_;

	TextField *username_input_;
	TextField *password_input_;
	TextField *password_confirmation_;
	TextField *server_input_;

	InputValidator *validator_;

	// Matrix client API provider.
	QSharedPointer<MatrixClient> client_;
};

#endif  // REGISTERPAGE_H
