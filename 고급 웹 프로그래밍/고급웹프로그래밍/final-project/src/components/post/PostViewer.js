import React, { useState } from "react";
import styled from "styled-components";
import palette from "../../lib/styles/palette";
import Responsive from "../common/Responsive";
import { Helmet } from "react-helmet-async";
import Button from "../common/Button";

import FavoriteRoundedIcon from "@mui/icons-material/FavoriteRounded";
import StarIcon from "@mui/icons-material/Star";

import Backdrop from "@mui/material/Backdrop";
import CircularProgress from "@mui/material/CircularProgress";
import CheckStudyModal from "./CheckStudyModal";
import ArrowForwardIosIcon from "@mui/icons-material/ArrowForwardIos";

import { Link } from "react-router-dom";
import { debounce } from "lodash";

const PostViewerBlock = styled(Responsive)`
  margin-top: 3rem;
`;

const PostHead = styled.div`
  border-bottom: 1px solid ${palette.gray[2]};
  padding-bottom: 2rem;
  margin-bottom: 2rem;
  display: flex;
  row-gap: 10px;
  flex-direction: column;
  h1 {
    font-size: 2rem;
    text-align: center;
    line-height: 1.5;
    margin: 0;
  }
`;

const SubInfo = styled.div`
  margin-top: 1rem;
  color: ${palette.gray[6]};
  text-align: right;

  // 구분자
  span + span:before {
    color: ${palette.gray[5]};
    padding: 0px 0.25rem;
    content: "\\B7";
  }
`;

const Tags = styled.div`
  margin-top: 0.5rem;
  .tag {
    display: inline-block;
    color: ${palette.cyan[7]};
    text-decoration: none;
    margin-right: 0.5rem;

    &:hover {
      color: ${palette.cyan[4]};
      cursor: pointer;
    }
  }
`;

const PostContent = styled.div`
  font-size: 1.3125rem;
  color: ${palette.gray[8]};
`;

const AttendanceButton = styled(Button)`
  width: 150px;
`;

const HeartItemIcon = styled(FavoriteRoundedIcon)`
  display: inline-block;
`;

const StarItemIcon = styled(StarIcon)`
  display: inline-block;
`;

const TitleContainer = styled.div`
  display: flex;
  justify-content: center;
  align-items: center;
  column-gap: 10px;
`;

const StudyCheckContainer = styled.div`
  text-align: right;
`;

const StudyCheckerTable = styled.table`
  border: 1px solid black;
  border-collapse: collapse;
  width: 90%;
  margin: 20px auto;

  td {
    border: 1px solid black;
    padding: 10px;
  }

  tr.info {
    background: ${palette.gray[5]};
  }

  tr.host {
    background: #ebd534;
  }
`;

const ArrowForwardIcon = styled(ArrowForwardIosIcon)`
  font-size: 12px;
  margin-right: 10px;
`;

const PostViewer = ({
  post,
  loading,
  error,
  actionButtons,
  user,
  onStudyIn,
  onSutdyOut,
  like_user,
}) => {
  const [modal, setModal] = useState(false);

  if (error) {
    // 백에서 포스트 못 찾으면 404뜨게 해놨음
    if (error.response && error.response.status === 404) {
      return (
        <PostViewerBlock>
          존재하지 않는 포스트입니다
        </PostViewerBlock>
      );
    }
    return <PostViewerBlock>오류 발생!</PostViewerBlock>;
  }

  if (loading || !post) {
    return (
      <Backdrop
        sx={{
          color: "#fff",
          zIndex: (theme) => theme.zIndex.drawer + 1,
        }}
        open={loading}
      >
        <CircularProgress color="inherit" />
      </Backdrop>
    );
  }

  const {
    title,
    body,
    publishedDate,
    creator: { username, _id: creatorId, email },
    tags,
    likeId: { like_user: like_user_onlyId },
    _id: postId,
    capacity,
  } = post;
  if (user) {
    var { _id: userId } = user;
  }

  const onCheck = () => {
    setModal(true);
  };

  const onConfirm = () => {
    setModal(false);
  };

  const data = (
    <StudyCheckerTable>
      <tbody>
        <tr className="info">
          <td>username</td>
          <td>email</td>
        </tr>
        <tr className="host">
          <td>
            {user && username && user.username === username && (
              <ArrowForwardIcon fontSize="12" />
            )}
            {username}
          </td>
          <td>{email}</td>
        </tr>

        {like_user.map(({ username, email }) => (
          <tr key={username}>
            <td>
              {user &&
                username &&
                user.username === username && (
                  <ArrowForwardIcon fontSize="12" />
                )}
              {username}
            </td>
            <td>{email}</td>
          </tr>
        ))}
      </tbody>
    </StudyCheckerTable>
  );
  return (
    <>
      <CheckStudyModal
        visible={modal}
        onConfirm={onConfirm}
        description={data}
      />
      <PostViewerBlock>
        <Helmet>
          <title>{title} - STUIK</title>
        </Helmet>

        <PostHead>
          <TitleContainer>
            {user ? (
              creatorId === userId ? (
                <StarItemIcon
                  style={{ color: palette.cyan[6] }}
                />
              ) : !like_user_onlyId.includes(userId) ? (
                <HeartItemIcon
                  style={{ color: palette.gray[5] }}
                />
              ) : (
                <HeartItemIcon
                  style={{ color: palette.cyan[6] }}
                />
              )
            ) : null}
            <h1>{title}</h1>
          </TitleContainer>
          <StudyCheckContainer>
            <Button cyan onClick={onCheck}>
              스터디 인원 확인
            </Button>
          </StudyCheckContainer>
          <SubInfo>
            <span>
              <b>{username}</b>
            </span>
            <span>
              {new Date(publishedDate).toLocaleDateString()}
            </span>
          </SubInfo>
          <Tags>
            {tags.map((tag) => (
              <Link
                className="tag"
                key={tag}
                to={`/?tag=${tag}`}
              >
                #{tag}
              </Link>
            ))}
          </Tags>
          {/* 스터디 참여 버튼 */}
          {user ? (
            creatorId === userId ? (
              <AttendanceButton
                disabled
                onClick={() => alert("스터디 장입니다.")}
              >
                스터디 장
              </AttendanceButton>
            ) : like_user_onlyId.includes(userId) ? (
              <AttendanceButton
                cyan
                onClick={() => {
                  onSutdyOut({ postId, userId });
                  alert("변경되었습니다.");
                }}
              >
                스터디 탈퇴
              </AttendanceButton>
            ) : like_user_onlyId.length >= +capacity ? (
              <AttendanceButton
                cyan
                disabled
                style={{ width: "200px" }}
              >
                스터디가 꽉 찼습니다.
              </AttendanceButton>
            ) : (
              <AttendanceButton
                cyan
                onClick={() => {
                  onStudyIn({ postId, userId });
                  alert("변경되었습니다.");
                }}
              >
                스터디 참여
              </AttendanceButton>
            )
          ) : null}
        </PostHead>
        {actionButtons}
        <PostContent
          dangerouslySetInnerHTML={{
            __html: body,
          }}
        />
      </PostViewerBlock>
    </>
  );
};

export default PostViewer;
