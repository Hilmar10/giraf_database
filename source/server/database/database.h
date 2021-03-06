/*
 * database.h
 *
 *  Created on: 11 Mar 2013
 *      Author: vixen
 */
#pragma once
#include <cstdio>
#include "queryresult.h"

class Database
{
public:
	Database(const char *address, unsigned int port,
			const char *database, const char *username,
			const char *password);
	virtual ~Database();

public:
	QueryResult *send_query(const char *query);
	//escape_query();
	//validate();
	void disconnect_database();
	int connect_database();

private:
	const char *_address;
	const char *_database;
	const char *_username;
	const char *_password;
	unsigned int _port;
	MYSQL *_conn;
};
