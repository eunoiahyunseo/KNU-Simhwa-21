import React from "react";
import styled, { css } from "styled-components";
import Responsive from "../common/Responsive";
import Button from "../common/Button";
import palette from "../../lib/styles/palette";

import SubInfo from "../common/SubInfo";
import Tags from "../common/Tags";

import ClassOutlinedIcon from "@mui/icons-material/ClassOutlined";
import LocalOfferOutlinedIcon from "@mui/icons-material/LocalOfferOutlined";
import FavoriteRoundedIcon from "@mui/icons-material/FavoriteRounded";
import StarIcon from "@mui/icons-material/Star";

import Backdrop from "@mui/material/Backdrop";
import CircularProgress from "@mui/material/CircularProgress";

const PostListBlock = styled(Responsive)`
  margin: 90px 50px;
  padding-bottom: 80px;
  z-index: 1;
`;

const PostGridLayout = styled.div`
  display: grid;
  grid-template-columns: repeat(2, minmax(100px, auto));
  grid-template-rows: repeat(3, minmax(170px, auto));
  row-gap: 80px;
  column-gap: 40px;
`;

const PostItemBlock = styled.div`
  outline: none;
  border-radius: 0.5rem;
  background: ${palette.gray[2]};
  cursor: pointer;
  height: 100%;
  ${(props) =>
    props.full &&
    css`
      border: 2px solid ${palette.cyan[5]}};
    `}

  &:before,
  &:after {
    content: "";
    position: absolute;
    top: 50%;
    left: 50%;
    width: 95%;
    height: 95%;
    transform: translate(-50%, -50%);
    transition: all 0.5s;
  }

  &:before {
    border-top: 2px solid ${palette.gray[5]};
    border-bottom: 2px solid ${palette.gray[5]};
    width: 0;
  }

  &:after {
    border-left: 2px solid ${palette.gray[5]};
    border-right: 2px solid ${palette.gray[5]};
    height: 0;
  }

  transition: all 0.5s ease;
`;

const SubPostBlock = styled.div`
  position: absolute;
  bottom: -12.5%;
  left: 0;
  right: 0;
  margin: auto;
  background: white;
  border-radius: 0.5rem;
  width: 70%;
  height: 25%;
  box-shadow: 0px 2px 10px 10px #eee;
  text-align: center;
  transition: all 0.4s ease;
`;

const PostItemTitle = styled.div`
  position: absolute;
  top: 55%;
  left: 50%;
  transform: translate(-50%, -50%);
  color: ${palette.gray[7]};
  font-size: 1.4rem;
  text-align: center;
`;

const PostItemIconContainer = styled.div`
  transition: all 0.5s ease;
  position: absolute;
  right: 1rem;
  top: 1rem;
`;
const PostItemIcon = styled(ClassOutlinedIcon)`
  font-size: 12px;
`;

const HeartItemContainer = styled.div`
  position: absolute;
  right: 3rem;
  top: 1rem;
`;

const HeartItemIcon = styled(FavoriteRoundedIcon)`
  display: inline-block;
`;

const StarItemIcon = styled(StarIcon)`
  display: inline-block;
`;

const TagIconContainer = styled.div`
  position: absolute;
  top: -5px;
  left: -7px;
  transition: all 0.5s ease;
`;

const TagIcon = styled(LocalOfferOutlinedIcon)`
  font-size: 12px;
`;

const WritePostButtonWrapper = styled.div`
  display: flex;
  justify-content: flex-end;
  margin-bottom: 2rem;

  a {
    text-decoration: none;
  }
`;

const Container = styled.div`
  position: relative;
  transition: all 0.5s ease;

  &:hover {
    transform: translateY(10px);
    .PostItem:before {
      width: 95%;
    }

    .PostItem:after {
      height: 95%;
    }

    .icon1 {
      transform: rotate(360deg) scale(1.4);
    }

    .icon2 {
      transform: rotate(90deg);
    }
  }
`;

const DescribeContainer = styled.div`
  position: absolute;
  top: 6rem;
  display: flex;
  flex-direction: column;
`;

const DescribeItemContainer = styled.div`
  display: flex;
  column-gap: 15px;

  margin-bottom: 10px;
`;

const CapacityContainer = styled.div`
  position: absolute;
  top: 3rem;
  left: 1rem;
  color: ${palette.cyan[6]};
  font-size: 12px;
  background: ${palette.gray[0]};
  padding: 5px 10px;
  border-radius: 1.5rem;
  font-weight: bold;
`;

const PostItem = ({ post, onPostClick, user }) => {
  const {
    publishedDate,
    tags,
    title,
    creator: { username, _id: creatorId },
    _id,
    likeId: { like_user },
    capacity,
  } = post;

  if (user) {
    var { _id: userId } = user;
  }

  return (
    <Container>
      <PostItemBlock
        onClick={() => onPostClick(username, _id)}
        className="PostItem"
        full={+capacity === +like_user.length}
      >
        <PostItemIconContainer className="icon1">
          <PostItemIcon style={{ color: "gray" }} />
        </PostItemIconContainer>
        <HeartItemContainer>
          {/* 만약 like_user안에 현재 접속해 있는 user의 id가 있다면 하트를 해준다.
            또한 중요한 예외처리가 있는데, 해당 post가 creator라면 별을 보여줘야 한다 ( 스터디장 표시 )
          */}
          {user ? (
            creatorId === userId ? (
              <StarItemIcon style={{ color: palette.cyan[6] }} />
            ) : !like_user.includes(userId) ? (
              <HeartItemIcon
                style={{ color: palette.gray[5] }}
              />
            ) : (
              <HeartItemIcon
                style={{ color: palette.cyan[6] }}
              />
            )
          ) : null}
        </HeartItemContainer>
        <PostItemTitle>
          {title}
          <br />
          {+capacity === +like_user.length && "(모집 완료)"}
        </PostItemTitle>
        <SubInfo
          username={username}
          publishedDate={publishedDate}
        />
        <CapacityContainer>
          {capacity} / {like_user.length}
        </CapacityContainer>
      </PostItemBlock>
      <SubPostBlock className="subPost">
        <TagIconContainer className="icon2">
          <TagIcon
            fontSize="small"
            style={{ color: palette.gray[5] }}
          />
        </TagIconContainer>
        <Tags tags={tags} />
      </SubPostBlock>
    </Container>
  );
};

const PostList = ({
  loading,
  error,
  posts,
  showWriteButton,
  onPostClick,
  user,
}) => {
  if (error) {
    return <PostListBlock>에러가 발생했습니다.</PostListBlock>;
  }

  return (
    <PostListBlock>
      <DescribeContainer>
        <DescribeItemContainer>
          <StarItemIcon style={{ color: palette.cyan[6] }} />
          <span>STUDY를 만든 사람 &#40;스터디장&#41;</span>
        </DescribeItemContainer>
        <DescribeItemContainer>
          <HeartItemIcon style={{ color: palette.gray[5] }} />
          <span>STUDY에 참여하지 않음</span>
        </DescribeItemContainer>
        <DescribeItemContainer>
          <HeartItemIcon style={{ color: palette.cyan[6] }} />
          <span>STUDY에 참여함</span>
        </DescribeItemContainer>
      </DescribeContainer>

      <WritePostButtonWrapper>
        {showWriteButton ? (
          <Button cyan to="/write">
            새 스터디 만들기
          </Button>
        ) : (
          <div style={{ marginTop: "13px" }}></div>
        )}
      </WritePostButtonWrapper>
      {/* not loading && exits posts array */}
      {(loading || !posts) && (
        <Backdrop
          sx={{
            color: "#fff",
            zIndex: (theme) => theme.zIndex.drawer + 1,
          }}
          open={loading}
        >
          <CircularProgress color="inherit" />
        </Backdrop>
      )}
      {!loading && posts && (
        <PostGridLayout>
          {posts.map((post) => (
            <PostItem
              post={post}
              key={post._id}
              onPostClick={onPostClick}
              user={user}
            />
          ))}
        </PostGridLayout>
      )}
    </PostListBlock>
  );
};

export default PostList;
