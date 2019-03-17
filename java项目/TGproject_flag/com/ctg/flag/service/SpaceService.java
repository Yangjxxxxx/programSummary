package com.ctg.flag.service;

import com.ctg.flag.pojo.entity.SpaceApply;

public interface SpaceService {
    void saveSpaceApply(SpaceApply spaceApply);

    SpaceApply getPendingSpaceApplyByUid(Integer uid);

    void deleteSpaceApplyByUid(Integer uid);

    Boolean existsByUidAndStateIn(Integer uid);
}
