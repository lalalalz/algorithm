cmake_minimum_required(VERSION 3.21)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

##################################################################################
# SUBDIRLIST 매크로 : 하위 프로젝트 디렉토리의 이름들을 result에 담아서 출력
# 입력값 파라미터 curdir
# 출력갑 파라미터 result
MACRO(SUBDIRLIST result curdir)
    FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
    SET(dirlist "")
    FOREACH(child ${children})
        STRING(FIND ${child} . isDir)
        STRING(FIND ${child} cmake isDebug)
        IF(IS_DIRECTORY ${curdir}/${child} AND ${isDir} AND ${isDebug})
            LIST(APPEND dirlist ${child})
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()
##################################################################################




##################################################################################
# SUBDIRLIST 매크로 실행
# 입력갑 ${CMAKE_SOURCE_DIR}
# 출력갑 SUBDIRS
SUBDIRLIST(SUBDIRS ${CMAKE_SOURCE_DIR})
##################################################################################




##################################################################################
# 매크로 결과값을 반복문을 이용하여 서브디렉토리 프로젝트 추가
FOREACH(subdir ${SUBDIRS})
    ADD_SUBDIRECTORY(${subdir})
    MESSAGE("ADD DIRECTORY : ${subdir}")
ENDFOREACH()
##################################################################################