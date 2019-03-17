package com.weizhi.redflower.service;

import com.weizhi.redflower.pojo.entity.User;

public interface UserService {
    /**
     * 依据前台给的code，向微信请求openid，
     * 依据openid判断在数据库中是否存在，
     * 存在，则判断是否已完善显示
     *    已完善，则设置session，返回成功
     *    未完善，设置session，返回需完善信息
     * 不存在，则创建用户，返回需完善信息
     * @param code 前台给的code
     * @return User Entity
     */
    User login(String openid,String encryptedData,String sessionKey,String iv);

    /**
     * 对用户信息进行更新
     *   1. 完善信息
     *   2. 修改信息
     *      ...
     * @param user 修改后的user
     */
    void update(User user);

    /**
     * 按用户id查询用户
     * @param id
     * @return
     */
    User getUserById(Integer id);
}
