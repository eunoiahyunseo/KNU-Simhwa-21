import React, { useState, useCallback, useEffect } from "react";
import styled from "styled-components";
import palette from "../../lib/styles/palette";

const TagBoxBlock = styled.div`
  width: 100%;
  border-top: 1px solid ${palette.gray[2]};
  padding-top: 1rem;
  margin: 1rem;

  h4 {
    color: ${palette.gray[8]};
    margin-top: 0px;
    margin-bottom: 0.875rem;
  }
`;

const TagForm = styled.form`
  border: 1px solid ${palette.gray[9]};
  width: 256px;
  border-radius: 4px;
  display: flex;

  input,
  button {
    outline: none;
    border: none;
    font-size: 1rem;
  }

  input {
    padding: 0.5rem;
    flex: 1;
    min-width: 0px;
    margin: 1px;
  }

  button {
    cursor: pointer;
    padding: 0px 1rem;
    background: ${palette.gray[7]};
    color: white;
    font-weight: bold;

    &:hover {
      background: ${palette.gray[6]};
    }
  }
`;

const TagListBlock = styled.div`
  display: flex;
  margin-top: 0.5rem;
`;

const Tag = styled.div`
  color: ${palette.gray[6]};
  margin-right: 0.5rem;
  cursor: pointer;

  &:hover {
    opacity: 0.5;
  }
`;

const TagItem = React.memo(({ tag, onRemove }) => (
  <Tag onClick={() => onRemove(tag)}>#{tag}</Tag>
));

const TagList = React.memo(({ tags, onRemove }) => (
  <TagListBlock>
    {tags.map((tag) => (
      <TagItem key={tag} tag={tag} onRemove={onRemove} />
    ))}
  </TagListBlock>
));

const TagBox = ({ onChangeTags, tags }) => {
  const [input, setInput] = useState("");
  const [localTags, setLocalTags] = useState([]);

  const insertTag = useCallback(
    (tag) => {
      if (!tag) return;
      if (localTags.includes(tag)) return;
      const nextTags = [...localTags, tag];
      // 이렇게 하면 redux의 상태가 바뀐다. 그럼 tags값이 밖뀌겠지? -> 그럼 리 랜더링이 진행되겠지
      onChangeTags(nextTags);
    },
    [localTags, onChangeTags]
  );

  useEffect(() => {
    setLocalTags(tags);
  }, [tags]);

  const onRemove = useCallback(
    (tag) => {
      const nextTags = localTags.filter((t) => t !== tag);
      onChangeTags(nextTags);
    },
    [localTags, onChangeTags]
  );

  const onChange = useCallback((e) => {
    const {
      target: { value },
    } = e;
    setInput(value);
  }, []);

  const onSubmit = useCallback(
    (e) => {
      e.preventDefault();
      insertTag(input.trim());
      setInput("");
    },
    [input, insertTag]
  );

  return (
    <TagBoxBlock>
      <h4>태그</h4>
      <TagForm onSubmit={onSubmit}>
        <input
          placeholder="태그를 입력하세요."
          value={input}
          onChange={onChange}
        />
        <button type="submit">추가</button>
      </TagForm>
      <TagList tags={localTags} onRemove={onRemove} />
    </TagBoxBlock>
  );
};

export default TagBox;
