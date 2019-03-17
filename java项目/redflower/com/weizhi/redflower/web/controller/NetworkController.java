package com.weizhi.redflower.web.controller;

import com.alibaba.fastjson.JSONObject;
import com.weizhi.redflower.enums.InfoStatusEnum;
import com.weizhi.redflower.pojo.dto.InfoDto;
import com.weizhi.redflower.pojo.dto.NetWorkDto;
import com.weizhi.redflower.pojo.dto.ResponseDto;
import com.weizhi.redflower.pojo.entity.Intimacy;
import com.weizhi.redflower.pojo.entity.Network;
import com.weizhi.redflower.pojo.entity.User;
import com.weizhi.redflower.pojo.entity.UserNetwork;
import com.weizhi.redflower.service.IntimacyService;
import com.weizhi.redflower.service.NetworkService;
import com.weizhi.redflower.service.UserNetworkService;
import com.weizhi.redflower.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.HttpSession;
import java.util.*;

@RestController
@RequestMapping(value = "/network")
public class NetworkController {

    private NetworkService networkService;

    private UserNetworkService userNetworkService;

    private UserService userService;

    private IntimacyService intimacyService;

    @Autowired
    public NetworkController(NetworkService networkService, UserNetworkService userNetworkService, UserService userService, IntimacyService intimacyService) {
        this.networkService = networkService;
        this.userNetworkService = userNetworkService;
        this.userService = userService;
        this.intimacyService = intimacyService;
    }

    /**
     * 创建新的人脉圈
     *
     * @Param name
     */
    @RequestMapping(value = "/addNetwork", method = RequestMethod.POST)
    public ResponseDto AddNetwork(@RequestParam("name") String name, HttpSession httpSession) {

        Integer userId = (Integer) httpSession.getAttribute("userId");
        if (userId == null) {
            return ResponseDto.failed("no login");
        }

        Network network = new Network();
        network.setName(name);

        if (network.getName() == null) {
            return ResponseDto.failed("failed");
        }

        networkService.insert(network);
        return ResponseDto.failed("succeed");
    }

    /**
     * 邀请更多人加入人脉网
     *
     * @param nid
     * @param uid
     */
    @RequestMapping(value = "/invitation", method = RequestMethod.POST)
    public ResponseDto Invite(@RequestParam("nid") Integer nid,
                              @RequestParam("uid") Integer uid, HttpSession httpSession) {

        Integer userId = (Integer) httpSession.getAttribute("userId");
        if (userId == null) {
            return ResponseDto.failed("no login");
        }

        if (userNetworkService.getUserNetworkByUidAndNid(uid, nid) != null) {
            return ResponseDto.failed("already join");
        }

        UserNetwork userNetwork = new UserNetwork();
        userNetwork.setNid(nid);
        userNetwork.setUid(uid);

        if (userNetwork.getNid() != null && userNetwork.getUid() != null) {
            return ResponseDto.succeed("invite successfully");
        }
        return ResponseDto.failed("failed");
    }

    /**
     * 查看我的人脉圈
     *
     * @param uid
     */
    @RequestMapping(value = "/myNetworks")
    public ResponseDto myNetworks(HttpSession httpSession) {
        Integer userId = (Integer) httpSession.getAttribute("userId");
        if (userId == null) {
            return ResponseDto.failed("no login");
        }

        JSONObject response = userNetworkService.myNetworks(userId);
        if (response == null) {
            return ResponseDto.failed("my networks are null");
        }

        return ResponseDto.succeed("query successfully", response);
    }

    /**
     * 人脉网界面个人信息
     *
     * @param uid1
     * @param uid2
     */
    @RequestMapping(value = "info", method = RequestMethod.POST)
    public ResponseDto info(@RequestParam("uid1") Integer uid1,
                            @RequestParam("uid2") Integer uid2,
                            HttpSession httpSession) {
        Integer userId = (Integer) httpSession.getAttribute("userId");
        if (userId == null) {
            return ResponseDto.failed("no login");
        }

        User user = userService.getUserById(uid1);
        if (user == null) {
            return ResponseDto.failed("uid1 is not exist");
        }

        Intimacy intimacy = intimacyService.getIntimacyByUid1AndUid2(uid1, uid2);
        if (intimacy == null) {
            return ResponseDto.failed("no connection");
        }

        if (intimacy.getValue() < InfoStatusEnum.rank.getValue()) {
            InfoDto infoDto = new InfoDto(uid1, user.getName(), user.getGender(), user.getDefinition(), InfoStatusEnum.LOW.getValue(), user.getWxid());
            return ResponseDto.succeed("succeed", infoDto);
        } else {
            return ResponseDto.succeed("succeed", new InfoDto(uid1, user.getName(), user.getGender(), user.getDefinition(), InfoStatusEnum.HIGH.getValue(), user.getWxid()));
        }
    }

    /**
     * 人脉网界面
     *
     * @param userId
     * @return
     */
    @RequestMapping(value = "/image", method = RequestMethod.POST)
    public ResponseDto getDifferentUser(@RequestParam("userId") Integer userId,
                                        HttpSession httpSession) {
        if (httpSession.getAttribute("userId") == null) {
            return ResponseDto.failed("no login");
        }

        if (userService.getUserById(userId) == null) {
            return ResponseDto.failed("no userId");
        }

        List<UserNetwork> userNetworkList = userNetworkService.getUserNetworksByUid(userId);
        if (userNetworkList.isEmpty()) {
            return ResponseDto.failed("you do not have network");
        }

        List<Integer> nids = new ArrayList<>();
        for (int i = 0; i < userNetworkList.size(); i++) {
            nids.add(userNetworkList.get(i).getNid());
        }

        //uids为userId所在所有人脉圈中所有人的id
        Set<Integer> uids = new HashSet<>();
        for (int i = 0; i < nids.size(); i++) {
            List<UserNetwork> userNetworkListBynidsI = userNetworkService.getUserNetworksByUid(nids.get(i));
            for (int j = 0; j < userNetworkListBynidsI.size(); j++) {
                uids.add(userNetworkListBynidsI.get(j).getUid());
            }
        }
        //low亲密度的uid
        List<Integer> lowUids = new ArrayList<>();
        //high亲密度的uid
        List<Integer> highUids = new ArrayList<>();

        for (Integer uid : uids) {
            //userid和uid之间的亲密度
            Integer intimacyValue = intimacyService.getIntimacyByUid1AndUid2(uid, userId).getValue();
            if (intimacyValue < InfoStatusEnum.rank.getValue()) {
                Integer temp = uid;
                lowUids.add(temp);
            } else {
                Integer temp = uid;
                highUids.add(temp);
            }
        }

        JSONObject mainUser = new JSONObject();
        mainUser.put(userService.getUserById(userId).getId().toString(), userService.getUserById(userId).getAvatarUrl());

        Random random = new Random();
        JSONObject maxUser = new JSONObject();
        //highuids小于4，全放进Json
        if (highUids.size() < 4) {
            for (Integer uid : highUids) {
                maxUser.put(userService.getUserById(highUids.get(uid)).getId().toString(),
                        userService.getUserById(highUids.get(uid)).getAvatarUrl());
            }
        } else {
            /**
             * 在highuids中随机取三个uid
             */
            //取3个不大于highuids.size的随机数
            Set<Integer> rands = new HashSet<>();
            while (rands.size() < 4) {
                rands.add(random.nextInt(highUids.size()));
            }
            for (Integer rand : rands) {
                maxUser.put(userService.getUserById(highUids.get(rand)).getId().toString(),
                        userService.getUserById(highUids.get(rand)).getAvatarUrl());
            }
        }

        JSONObject minUser = new JSONObject();
        //lowuids小于7，全放进Json
        if (lowUids.size() < 7) {
            for (Integer uid : lowUids) {
                minUser.put(userService.getUserById(lowUids.get(uid)).getId().toString(),
                        userService.getUserById(lowUids.get(uid)).getAvatarUrl());
            }
        } else {
            /**
             * 在lowuids中随机取6个uid
             */
            //取6个不大于lowuids.size的随机数
            Set<Integer> rands = new HashSet<>();
            while (rands.size() < 7) {
                rands.add(random.nextInt(lowUids.size()));
            }
            for (Integer rand : rands) {
                minUser.put(userService.getUserById(lowUids.get(rand)).getId().toString(),
                        userService.getUserById(lowUids.get(rand)).getAvatarUrl());
            }
        }

        NetWorkDto netWorkDto = new NetWorkDto(mainUser, maxUser, minUser);
        return ResponseDto.succeed("succeed", netWorkDto);
    }
}


