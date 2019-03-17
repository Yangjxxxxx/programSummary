package com.yjx;

import java.sql.*;
import org.json.JSONObject;
import java.util.ArrayList;

public class Sql {
	
	static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
    static final String DB_URL = "jdbc:mysql://localhost:3306/api";
    
    static final String USER = "root";
    static final String PASS = "981002";
    
    public void browse(JSONObject data) {
    	Connection conn = null;
    	Statement stmt  = null;
    	try {
    		Class.forName(JDBC_DRIVER);
    		
    		System.out.println("连接数据库。。。");
    		conn = DriverManager.getConnection(DB_URL,USER,PASS);
    		
    		stmt = conn.createStatement();
    		String sql = "select username, password from users";
    		ResultSet rs = stmt.executeQuery(sql);
    		
    		while (rs.next()) {
    			String username = rs.getString("username");
    			String password = rs.getString("password");
    			
    			data.put(username, password);
    		}
    		rs.close();
    		stmt.close();
    		conn.close();
    	}catch(SQLException se) {
    		se.printStackTrace();
    	}catch(Exception e) {
    		e.printStackTrace();
    	}finally {
    		//关闭资源
    		try{
    			if(stmt!=null) stmt.close();
    		}catch(SQLException se2) {
    		}
    		try{
    			if(conn!=null) conn.close();
    		}catch(SQLException se) {
    			se.printStackTrace();
    		}
    	}
    }
    //添加用户
    public boolean insert(String user,String pass) {
    	Connection conn = null;
    	Statement stmt  = null;
    	try {
    		Class.forName(JDBC_DRIVER);
    		
    		System.out.println("连接数据库。。。");
    		conn = DriverManager.getConnection(DB_URL,USER,PASS);
    		
    		stmt = conn.createStatement();
    		String sql = "insert into users values(\""
    				+ user + "\",\"" + pass + "\")";
    		System.out.println(sql);
    		stmt.executeUpdate(sql);
    		stmt.close();
    		conn.close();
    		return true;
    	}catch(SQLException se) {
    		se.printStackTrace();
    		return false;
    	}catch(Exception e) {
    		e.printStackTrace();
    		return false;
    	}finally {
    		//关闭资源
    		try{
    			if(stmt!=null) stmt.close();
    		}catch(SQLException se2) {
    		}
    		try{
    			if(conn!=null) conn.close();
    		}catch(SQLException se) {
    			se.printStackTrace();
    		}
    	}
    }
    //用户登录
    public boolean login(String user,String pass) {
    	Connection conn = null;
    	Statement stmt  = null;
    	try {
    		Class.forName(JDBC_DRIVER);
    		
    		System.out.println("连接数据库。。。");
    		conn = DriverManager.getConnection(DB_URL,USER,PASS);
    		
    		stmt = conn.createStatement();
    		String sql = "select password from users where username=\""
    				+ user + "\"";
    		System.out.println(sql);
    		ResultSet rs = stmt.executeQuery(sql);
    		if(rs.next()) {
    			if(rs.getString("password").equals(pass)) {
        			stmt.close();
        			conn.close();
        			return true;
        		}else {
        		stmt.close();
        		conn.close();
        		return false;
        		}
    		}
    		else
    			return false;
    	}catch(SQLException se) {
    		se.printStackTrace();
    		return false;
    	}catch(Exception e) {
    		e.printStackTrace();
    		return false;
    	}finally {
    		//关闭资源
    		try{
    			if(stmt!=null) stmt.close();
    		}catch(SQLException se2) {
    		}
    		try{
    			if(conn!=null) conn.close();
    		}catch(SQLException se) {
    			se.printStackTrace();
    		}
    	}
    }
    
    //获取文章列表
    public boolean browseArticle(ArrayList<JSONObject> articleList) {
    	Connection conn = null;
    	Statement stmt  = null;
    	try {
    		Class.forName(JDBC_DRIVER);
    		
    		System.out.println("连接数据库。。。");
    		conn = DriverManager.getConnection(DB_URL,USER,PASS);
    		
    		stmt = conn.createStatement();
    		String sql = "select title,author,date from article";
    		ResultSet rs = stmt.executeQuery(sql);
    		
    		while (rs.next()) {
    			
    			String title = rs.getString("title");
    			String author = rs.getString("author");
    			String date = rs.getString("date");
    			
    			JSONObject json = new JSONObject();
    			json.put("title", title);
    			json.put("author", author);
    			json.put("data", date);
    			articleList.add(json);
    			
    		}
    		rs.close();
    		stmt.close();
    		conn.close();
    		return true;
    	}catch(SQLException se) {
    		se.printStackTrace();
    		return false;
    	}catch(Exception e) {
    		e.printStackTrace();
    		return false;
    	}finally {
    		//关闭资源
    		try{
    			if(stmt!=null) stmt.close();
    		}catch(SQLException se2) {
    		}
    		try{
    			if(conn!=null) conn.close();
    		}catch(SQLException se) {
    			se.printStackTrace();
    		}
    	}
    }
    //添加文章
    public boolean addArticle(String title,String author,String date,String article) {    
    	Connection conn = null;
    	Statement stmt  = null;
    	try {
    		Class.forName(JDBC_DRIVER);
    		
    		System.out.println("连接数据库。。。");
    		conn = DriverManager.getConnection(DB_URL,USER,PASS);
    		
    		stmt = conn.createStatement();
    		String sql = "insert into article values(\"" + title +"\",\""+ author + "\",\"" + date + "\",\""+ article + "\")";
    		stmt.executeUpdate(sql);
    		
    		stmt.close();
    		conn.close();
    		return true;
    	}catch(SQLException se) {
    		se.printStackTrace();
    		return false;
    	}catch(Exception e) {
    		e.printStackTrace();
    		return false;
    	}finally {
    		//关闭资源
    		try{
    			if(stmt!=null) stmt.close();
    		}catch(SQLException se2) {
    		}
    		try{
    			if(conn!=null) conn.close();
    		}catch(SQLException se) {
    			se.printStackTrace();
    		}
    	}
    }
    //删除文章
    public boolean deleteArticle(String title) {      
    	Connection conn = null;
    	Statement stmt  = null;
    	try {
    		Class.forName(JDBC_DRIVER);
    		
    		System.out.println("连接数据库。。。");
    		conn = DriverManager.getConnection(DB_URL,USER,PASS);
    		
    		stmt = conn.createStatement();
    		String sql = "delete from article where title=\"" + title + "\"";
    		stmt.executeUpdate(sql);
    		
    		stmt.close();
    		conn.close();
    		return true;
    	}catch(SQLException se) {
    		se.printStackTrace();
    		return false;
    	}catch(Exception e) {
    		e.printStackTrace();
    		return false;
    	}finally {
    		//关闭资源
    		try{
    			if(stmt!=null) stmt.close();
    		}catch(SQLException se2) {
    		}
    		try{
    			if(conn!=null) conn.close();
    		}catch(SQLException se) {
    			se.printStackTrace();
    		}
    	}
    }
    //获取文章内容
    public boolean attainArticle(String title,StringBuffer text) {      
    	Connection conn = null;
    	Statement stmt  = null;
    	try {
    		Class.forName(JDBC_DRIVER);
    		
    		System.out.println("连接数据库。。。");
    		conn = DriverManager.getConnection(DB_URL,USER,PASS);
    		
    		stmt = conn.createStatement();
    		String sql = "select article from article where title=\"" + title + "\"";
    		ResultSet rs = stmt.executeQuery(sql);
    		
    		while(rs.next()) {
    			String t = rs.getString("article");
    			text.append(t);
    			
    		}
    		
    		
    		stmt.close();
    		conn.close();
    		return true;
    	}catch(SQLException se) {
    		se.printStackTrace();
    		return false;
    	}catch(Exception e) {
    		e.printStackTrace();
    		return false;
    	}finally {
    		//关闭资源
    		try{
    			if(stmt!=null) stmt.close();
    		}catch(SQLException se2) {
    		}
    		try{
    			if(conn!=null) conn.close();
    		}catch(SQLException se) {
    			se.printStackTrace();
    		}
    	}
    }
    //修改文章
    public boolean modifyArticle(String title,String text) {      
    	Connection conn = null;
    	Statement stmt  = null;
    	try {
    		Class.forName(JDBC_DRIVER);
    		
    		System.out.println("连接数据库。。。");
    		conn = DriverManager.getConnection(DB_URL,USER,PASS);
    		
    		stmt = conn.createStatement();
    		String sql = "update article set article=\""+ text +"\" where title=\"" + title + "\"";
    		stmt.executeUpdate(sql);
    	
    		stmt.close();
    		conn.close();
    		return true;
    	}catch(SQLException se) {
    		se.printStackTrace();
    		return false;
    	}catch(Exception e) {
    		e.printStackTrace();
    		return false;
    	}finally {
    		//关闭资源
    		try{
    			if(stmt!=null) stmt.close();
    		}catch(SQLException se2) {
    		}
    		try{
    			if(conn!=null) conn.close();
    		}catch(SQLException se) {
    			se.printStackTrace();
    		}
    	}
    }

}